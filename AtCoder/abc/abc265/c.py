from collections import deque

c_di = {
    'U': (-1, 0), 
    'D': (1, 0), 
    'L': (0, -1), 
    'R': (0, 1)
}

def main():
    h, w = map(int, input().split())
    g = [input() for _ in range(h)]

    seen = [[False]*w for _ in range(h)]
    seen[0][0] = True
    q = deque()
    q.append((0, 0))
    
    while len(q) > 0:
        y, x = q.popleft()

        di = g[y][x]

        ny = y + c_di[di][0]
        nx = x + c_di[di][1]

        if ny<0 or ny>=h or nx<0 or nx>=w:
            print(y+1, x+1)
            exit()

        if seen[ny][nx]:
            print(-1)
            exit()

        seen[ny][nx] = True

        q.append((ny, nx))



if __name__ == '__main__':
    main()