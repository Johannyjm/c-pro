from collections import deque
h, w = map(int, input().split())
a = [input() for _ in range(h)]

field = [[0] * w for _ in range(h)]
for i in range(h):
    for j in range(w):
        if(a[i][j] == '#'): field[i][j] = 1

q = deque()
q.append((0, 0))
field[0][0] = 0

dy = (0, 1)
dx = (1, 0)

while(len(q) != 0):
    y, x = q.popleft()

    cnt = 0
    for di in range(2):
        ny = y + dy[di]
        nx = x + dx[di]

        if ny>=h or ny<0 or nx>=w or nx<0: continue
        if field[ny][nx] == 0: continue
        
        cnt += 1
        q.append((ny, nx))
        field[ny][nx] = 0

    if cnt > 1:
        print("Impossible")
        exit()

rest = 0
for i in range(h):
    for j in range(w):
        rest += field[i][j]

if rest == 0: print("Possible")
else: print("Impossible")
        
