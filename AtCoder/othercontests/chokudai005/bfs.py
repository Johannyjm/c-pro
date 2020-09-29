from collections import deque, Counter
import itertools
import copy

id, n, k = map(int, input().split())
s = [list(map(int, list(input()))) for _ in range(n)]

dy = (0, 1, 0, -1)
dx = (1, 0, -1, 0)


def process(s, color):
    ret = []

    for i in range(n):
        for j in range(n):

            if(s[i][j] == color): continue
            ret.append([i, j, color])

            col = s[i][j]

            s[i][j] = color
            q = deque()
            q.append((i, j))
            while(len(q) != 0):
                cy, cx = q.popleft()

                for dir in range(4):
                    ny = cy + dy[dir]
                    nx = cx + dx[dir]

                    if(ny<0 or ny>=n or nx<0 or nx>=n): continue
                    if(s[ny][nx] != col): continue

                    s[ny][nx] = color
                    q.append((ny, nx))
            
    return s, ret




def calcScore(Q, S):
    Sin1d = list(itertools.chain.from_iterable(S))
    cnt = Counter(Sin1d) # Listなど
    # print(cnt)

    maxColor = 1
    maxPanels = cnt[1]
    for i in range(2, k + 1):
        if cnt[i] > maxPanels:
            maxPanels = cnt[i]
            maxColor = i

    return 100 * maxPanels - Q 


def main():
    global s

    res = None
    mx_score = -1
    for color in range(1, 10):
        s_ = copy.deepcopy(s)
        s_, queries = process(s_, color)
        score = calcScore(len(queries), s_)
        # print(color, score)
        if(score > mx_score):
            mx_score = score
            res = queries


    print(len(res))
    for q in res:
        print(q[0]+1, q[1]+1, q[2])


if __name__ == "__main__":
    main()