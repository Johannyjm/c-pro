import sys
sys.setrecursionlimit(10**6)

class UnionFind:
    
    def __init__(self, n: int) -> None:
        self.p = [-1] * n
        self.r = [1] * n
    
    def find(self, x: int) -> int:
        if(self.p[x] == -1): return x
        self.p[x] = self.find(self.p[x])
        return self.p[x]
    
    def unite(self, x: int, y: int) -> None:
        x = self.find(x)
        y = self.find(y)

        if(x == y): return
        if(self.r[x] > self.r[y]): x, y = y, x
        if(self.r[x] == self.r[y]): self.r[y] += 1

        self.p[x] = y

    def same(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)


def main():
    n, q = map(int, input().split())
    uf = UnionFind(n)

    for _ in range(q):
        com, a, b = map(int, input().split())
        a -= 1
        b -= 1

        if(com == 0): uf.unite(a, b)
        if(com == 1):
            if(uf.find(a) == uf.find(b)):
                print(1)
            else:
                print(0)


if __name__ == "__main__":
    main()