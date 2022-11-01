from collections import deque
import random

direction = ['F', 'B', 'L', 'R']
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

h = 10
w = 10
board = [[None]*w for _ in range(h)]
f = list(map(int, input().split()))

def put_candy(n, idx):
    
    ptr = 0

    for i in range(h):
        for j in range(w):

            if board[i][j] is None:
                ptr += 1

                if n == ptr:
                    board[i][j] = f[idx]
                    return

def calc_score():
    
    def bfs(sy, sx, col):
        cnt = 1
        q = deque()
        q.append((sy, sx))
        seen[ny][nx] = True

        while len(q) != 0:

            y, x = q.popleft()

            for di in range(4):
                ny = y + dy[di]
                nx = x + dx[di]

                if ny>=h or ny<0 or nx>=w or nx<0: continue
                if board[ny][nx] != col: continue
                if seen[ny][nx]: continue

                seen[ny][nx] = True
                cnt += 1
                q.append((ny, nx))
        
        return cnt


    ret = 0

    seen = [[False]*w for _ in range(h)]

    for i in range(h):
        for j in range(w):
            
            if seen[i][j]: continue
            if board[i][j] is None: continue

            count = bfs(i, j, f[i][j])

            ret += count ** 2
    
    return ret

            

def main():

    for i in range(100):
        _ = int(input())
        print(direction[random.randint(0, 3)])

if __name__ == '__main__':
    main()