from collections import deque
dy = (0, 1, 0, -1)
dx = (1, 0, -1, 0)

def grid_bfs(grid, sy, sx, wall='#'): # returns dist[h][w]
    h = len(grid)
    w = len(grid[0])

    q = deque()
    q.append((sy, sx))

    INF = 1 << 60
    dist = [[INF]*w for _ in range(h)]
    dist[sy][sx] = 0

    while len(q) > 0:
        y, x = q.popleft()

        for di in range(4):
            ny = y + dy[di]
            nx = x + dx[di]

            if ny<0 or ny>=h or nx<0 or nx>=w: continue
            if grid[ny][nx] == wall: continue
            if dist[ny][nx] != INF: continue

            dist[ny][nx] = dist[y][x] + 1
            q.append((ny, nx))

    return dist

def main():

    h, w = map(int, input().split())
    sy, sx = map(int, input().split())
    gy, gx = map(int, input().split())

    sy, sx = sy-1, sx-1
    gy, gx = gy-1, gx-1

    grid = [input() for _ in range(h)]

    dist = grid_bfs(grid, sy, sx)

    print(dist[gy][gx])

if __name__ == '__main__':
    main()