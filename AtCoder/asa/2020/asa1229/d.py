from collections import deque
h, w = map(int, input().split())
s = [list(input()) for _ in range(h)]

dx = (0, 1, 0, -1)
dy = (1, 0, -1, 0)
INF = 99999


res = 0
for si in range(h):
    for sj in range(w):

        if(s[si][sj] == '#'): continue

        dist = [[INF] * w for _ in range(h)]
        dist[si][sj] = 0

        q = deque()
        q.append((si, sj))

        while(len(q) > 0):
            y, x = q.popleft()

            for di in range(4):
                ny = y + dy[di]
                nx = x + dx[di]

                if(ny<0 or ny>=h or nx<0 or nx>=w): continue
                if(dist[ny][nx] != INF): continue
                if(s[ny][nx] == '#'): continue

                dist[ny][nx] = dist[y][x] + 1

                q.append((ny, nx))
        
        cand = 0

        for i in range(h):
            for j in range(w):

                if(dist[i][j] != INF): cand = max(cand, dist[i][j])
        
        res = max(res, cand)

print(res)

