from collections import deque, Counter
import itertools
import copy
import random

id, n, k = map(int, input().split())
s = [list(map(int, list(input()))) for _ in range(n)]

dy = (0, 1, 0, -1)
dx = (1, 0, -1, 0)


def process(y, x):
    print(y, x)
    ret = []

    while True:
        orig = s[y][x]
        cnt = [0] * (k+1)
        q = deque()
        q.append((y, x))
        seen = [[False] * n] * n

        while(len(q) != 0):
            cy, cx = q.popleft()

            for dir in range(4):
                ny = cy + dy[dir]
                nx = cx + dx[dir]

                if(ny<0 or ny>=n or nx<0 or nx>=n): continue
                
                if(s[ny][nx] != orig):
                    cnt[s[ny][nx]] += 1
                    continue

                if(seen[ny][nx]): continue

                seen[ny][nx] = True
                q.append((ny, nx))
    
        mx_n = max(cnt)
        color = cnt.index(mx_n)
        print(color, cnt)
        if(mx_n == 0): break

        ret.append([y+1, x+1, color])
        col = s[y][x]
        s[y][x] = color
        q = deque()
        q.append((y, x))

        while(len(q) != 0):
            cy, cx = q.popleft()

            for dir in range(4):
                ny = cy + dy[dir]
                nx = cx + dx[dir]

                if(ny<0 or ny>=n or nx<0 or nx>=n): continue
                if(s[ny][nx] != col): continue

                s[ny][nx] = color
                q.append((ny, nx))
        
    
    for i in range(n):
        for j in range(n): print(s[i][j], end=' ')
        print()
            
    return ret




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

def biggest():
    return random.randint(0, n-1), random.randint(0, n-1)

def main():
    global s

    res = None
    mx_score = -1

    by, bx = biggest()

    # ress = []
    # mn = 101010101
    # resi = -1
    # for i in range(5):
    res = process(by, bx)
        # ress.append(res)
        # if(mn > len(res)):
        #     mn = len(res)
        #     resi = i

    print(len(res))
    for q in res:
        print(q[0], q[1], q[2])


if __name__ == "__main__":
    main()