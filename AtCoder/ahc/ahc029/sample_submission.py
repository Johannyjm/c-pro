from dataclasses import dataclass
from enum import Enum
import sys

MAX_INVEST_LEVEL = 20

@dataclass
class Project:
    h: int
    v: int


class CardType(Enum):
    WORK_SINGLE = 0
    WORK_ALL = 1
    CANCEL_SINGLE = 2
    CANCEL_ALL = 3
    INVEST = 4


@dataclass
class Card:
    t: CardType
    w: int
    p: int

class Judge:

    def __init__(self, n: int, m: int, k: int):
        self.n = n
        self.m = m
        self.k = k

    def read_initial_cards(self) -> list[Card]:
        cards = []
        for _ in range(self.n):
            t, w = map(int, input().split())
            cards.append(Card(CardType(t), w, 0))
        return cards

    def read_projects(self) -> list[Project]:
        projects = []
        for _ in range(self.m):
            h, v = map(int, input().split())
            projects.append(Project(h, v))
        return projects

    def use_card(self, c: int, m: int) -> None:
        print(f"{c} {m}", flush=True)

    def read_money(self) -> int:
        return int(input())

    def read_next_cards(self) -> list[Card]:
        cards = []
        for _ in range(self.k):
            t, w, p = map(int, input().split())
            cards.append(Card(CardType(t), w, p))
        return cards

    def select_card(self, r: int) -> None:
        print(r, flush=True)

    def comment(self, message: str) -> None:
        print(f"# {message}")


class Solver:

    def __init__(self, n: int, m: int, k: int, t: int):
        self.n = n
        self.m = m
        self.k = k
        self.t = t
        self.judge = Judge(n, m, k)
        self.project_cospas = []  # コスパのリストを初期化

    def solve(self) -> int:
        self.turn = 0
        self.money = 0
        self.invest_level = 0
        self.cards = self.judge.read_initial_cards()
        self.projects = self.judge.read_projects()

        for _ in range(self.t):
            use_card_i, use_target = self._select_action()
            if self.cards[use_card_i].t == CardType.INVEST:
                self.invest_level += 1
            # example for comments
            self.judge.comment(f"used {self.cards[use_card_i]} to target {use_target}")
            self.judge.use_card(use_card_i, use_target)
            assert self.invest_level <= MAX_INVEST_LEVEL

            self.projects = self.judge.read_projects()
            self.money = self.judge.read_money()

            next_cards = self.judge.read_next_cards()
            select_card_i = self._select_next_card(next_cards)
            self.cards[use_card_i] = next_cards[select_card_i]
            self.judge.select_card(select_card_i)
            self.money -= next_cards[select_card_i].p
            assert self.money >= 0

            self.turn += 1

        return self.money

    # def _select_action(self) -> tuple[int, int]:
    #     # TODO: implement your strategy
    #     return (0, 0)

    def calculate_work_single_score(self, card_index, project_index):
        K_s = 1
        card = self.cards[card_index]
        project = self.projects[project_index]
        V = project.v if project.h <= card.w else 0  # プロジェクトが完了する場合の価値
        P = max(0, -(project.h - card.w))  # ペナルティ
        return V - K_s * P

    def calculate_work_all_score(self, card_index):
        K_a = 1
        card = self.cards[card_index]
        V = sum(project.v for project in self.projects if project.h <= card.w)  # 完了するプロジェクトの価値の合計
        P = sum(max(0, -(project.h - card.w)) for project in self.projects)  # ペナルティの合計
        return V - K_a * P
    
    def update_project_cospas(self, project):
        if project.h > 0:
            self.project_cospas.append(project.v / project.h)

    def average_project_cospa(self):
        if self.project_cospas:
            return sum(self.project_cospas) / len(self.project_cospas)
        else:
            return 0

    def calculate_cancel_score(self, project_index):
        current_cospa = self.average_project_cospa()
        project = self.projects[project_index]
        project_cospa = project.v / project.h if project.h > 0 else 0

        # スコアリングロジック: 平均より十分に低いコスパなら高スコア
        if project_cospa < current_cospa * 0.5:  # 例: 平均の50%未満なら高スコア
            return 1 / project_cospa  # スコアを定義
        else:
            return 0
        
    # def calculate_cancel_single_score(self, project_index):
    #     # コスパの計算方法を定義する必要がある
    #     project = self.projects[project_index]
    #     # コスパが平均よりも十分悪い場合にスコアを加算するロジックをここに記述
    #     return -float('inf')

    def _select_action(self):
        best_score = -float('inf')
        best_action = (0, 0)

        # 各カードについてスコアを計算
        for i, card in enumerate(self.cards):
            if card.t == CardType.INVEST:
                return i, 0  # Investカードは最優先

            elif card.t == CardType.WORK_SINGLE:
                for j, project in enumerate(self.projects):
                    score = self.calculate_work_single_score(i, j)
                    if score > best_score:
                        best_score = score
                        best_action = (i, j)

            elif card.t == CardType.WORK_ALL:
                score = self.calculate_work_all_score(i)
                if score > best_score:
                    best_score = score
                    best_action = (i, 0)

            elif card.t == CardType.CANCEL_SINGLE:
                for j, project in enumerate(self.projects):
                    score = self.calculate_cancel_score(i, j)
                    if score > best_score:
                        best_score = score
                        best_action = (i, j)


        return best_action

    # def _select_next_card(self, next_cards: list[Card]) -> int:
    #     # TODO: implement your strategy
    #     return 0
    
    def _select_next_card(self, next_cards: list[Card]) -> int:
        # ゲームの前半でInvestカードが出現し、購入可能な場合はそれを最優先で選択
        if self.turn < self.t * 0.5:
            for i, card in enumerate(next_cards):
                if card.t == CardType.INVEST and self.money >= card.p:
                    return i
        
        if self.t * 0.5 <= self.turn < self.t * 0.75:
            for i, card in enumerate(next_cards):
                if card.t == CardType.INVEST and self.money >= card.p * 2:
                    return i

        # ゲームの後半では、デフォルトのカードを選択
        # if self.turn >= self.t // 2:
        #     return 0

        best_card_index = 0  # デフォルトで0番目のカードを選択
        best_value = 0

        for i, card in enumerate(next_cards):
            if card.t in [CardType.WORK_SINGLE, CardType.WORK_ALL] and i != 0:
                work_value = card.w if card.t == CardType.WORK_SINGLE else card.w * len(self.projects)
                efficiency = work_value / (card.p + 1)

                if efficiency > best_value:
                    best_card_index = i
                    best_value = efficiency

        # 手元に十分なお金があるか確認
        if self.turn < self.t * 0.5:
            k_value = 2
        elif self.turn < self.t * 0.75:
            k_value = 4
        elif self.turn < self.t * 0.90:
            k_value = 10
        else:
            k_value = 20   
        
        if self.money >= next_cards[best_card_index].p * k_value:
            return best_card_index
        else:
            return 0  # お金が不足している場合はデフォルトのカードを選択


def main():
    n, m, k, t = map(int, input().split())
    solver = Solver(n, m, k, t)
    score = solver.solve()
    print(f"score:{score}", file=sys.stderr)


if __name__ == "__main__":
    main()
