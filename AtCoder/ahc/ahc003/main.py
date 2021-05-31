import random
from heapq import heapify, heappop, heappush

random.seed(46)

h = 30
w = 30
grid = [[0] * w for _ in range(h)]
D = int(random.uniform(100, 2001))
M = random.choice([1, 2])

hij = [[0] * w for _ in range(h)]

Hip = [[0] * M for _ in range(h)]
for i in range(h):
    for p in range(M):
        Hip[i][p] = int(random.uniform(1000 + D, 9000 - D + 1))

xiM = [[0] * (M + 1) for _ in range(h)]
for i in range(h):
    xiM[i][0] = 0
    xiM[i][-1] = 29
    if M == 2:
        xiM[i][1] = int(random.uniform(1, 29))

delta = [[0] * (w-1) for _ in range(h)]
for i in range(h):
    for j in range(w-1):
        delta[i][j] = int(random.uniform(-D, D+1))

for i in range(h):
    for p in range(M):
        for j in range(xiM[i][p], xiM[i][p+1]):
            hij[i][j] = Hip[i][p] + delta[i][j]


vij = [[0] * w for _ in range(h)]

Vjp = [[0] * M for _ in range(w)]
for j in range(w):
    for p in range(M):
        Vjp[j][p] = int(random.uniform(1000 + D, 9000 - D + 1))

yjM = [[0] * (M + 1) for _ in range(w)]
for j in range(w):
    yjM[j][0] = 0
    yjM[j][-1] = 29
    if M == 2:
        yjM[j][1] = int(random.uniform(1, 29))

gamma = [[0] * w for _ in range(h-1)]
for i in range(h-1):
    for j in range(w):
        gamma[i][j] = int(random.uniform(-D, D+1))

for j in range(h):
    for p in range(M):
        for i in range(yjM[j][p], yjM[j][p+1]):
            vij[i][j] = Vjp[j][p] + gamma[i][j]



def printmat(mat):
    print()
    for i in range(len(mat)):
        for e in mat[i]: print(e, end=' ')
        print()
    print()

# printmat(hij)
# printmat(vij)


HIJ = [0] * (h * w)
VIJ = [0] * (h * w)
for i in range(h):
    for j in range(w):
        HIJ[i*w+j] = hij[i][j]

for i in range(h):
    for j in range(w):
        VIJ[i*w+j] = vij[i][j]




INF = float('inf')
dy = (1, 0, -1, 0)
dx = (0, 1, 0, -1)
def dijkstra(sy, sx):
    #ret = [[INF] * w for _ in range(h)]
    RET = [INF] * (h*w)
    #ret[sy][sx] = 0
    RET[sy*w+sx] = 0

    pq = []
    heappush(pq, (0, (sy, sx)))

    while len(pq) > 0:
        now = heappop(pq)
        y, x = now[1]
        #if ret[y][x] != now[0]: continue
        if RET[y*w+x] != now[0]: continue

        for di in range(4):
            ny = y + dy[di]
            nx = x + dx[di]

            if ny<0 or ny>=h or nx<0 or nx>=w: continue
            
            if di % 2 == 0:
                #cost = vij[y][x]
                cost = VIJ[y*w+x]
            else:
                #cost = hij[y][x]
                cost = HIJ[y*w+x]

            #if ret[ny][nx] > ret[y][x] + cost:
                #ret[ny][nx] = ret[y][x] + cost
                #heappush(pq, (ret[ny][nx], (ny, nx)))
            if RET[ny*w+nx] > RET[y*w+x] + cost:
                RET[ny*w+nx] = RET[y*w+x] + cost
                heappush(pq, (RET[ny*w+nx], (ny, nx)))

    #return ret    
    return RET

cmd = ('U', 'L', 'D', 'R')
def reconstruction(dist, sy, sx, ty, tx):
    ret = [(ty, tx)]
    ter = ''

    now = ty, tx
    while now != (sy, sx):
        y, x = now

        for di in range(4):
            py = y + dy[di]
            px = x + dx[di]

            if py<0 or py>=h or px<0 or px>=w: continue

            if di % 2 == 0:
                #diff = vij[py][px]
                diff = VIJ[py*w+px]
            else:
                #diff = hij[py][px]
                diff = HIJ[py*w+px]
            
            #if dist[y][x] - dist[py][px] > 0 and dist[y][x] - dist[py][px] == diff:
            if dist[y*w+x] - dist[py*w+px] > 0 and dist[y*w+x] - dist[py*w+px] == diff:
                ter += cmd[di]
                ret.append((py, px))
                break
        
        now = py, px
    
    return ret[::-1], ter[::-1]


# cursor = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}
def update(sy, sx, indices, scale):

    # y, x = sy, sx
    # for c in pk:
    #     if c in ('U', 'D'):
    #         vij[y][x] = int(vij[y][x] * scale)
    #     else:
    #         hij[y][x] = int(hij[y][x] * scale)
        
    #     y, x = y+cursor[c][0], x+cursor[c][1]
    
    y, x = sy, sx
    for ny, nx in indices[1: ]:
        if y == ny:
            #hij[y][x] = int(hij[y][x] * scale)
            HIJ[y*w+x] = int(HIJ[y*w+x] * scale)
        else:
            #vij[y][x] = int(vij[y][x] * scale)
            VIJ[y*w+x] = int(VIJ[y*w+x] * scale)

        y, x = ny, nx




for _ in range(1000):
    sy, sx, ty, tx = map(lambda x: int(x)-1, input().split())

    dist = dijkstra(sy, sx)
    # printmat(dist)

    indices, pk = reconstruction(dist, sy, sx, ty, tx)
    print(pk, flush=True)
    # print(indices)

    #cost_hat = dist[ty][tx]
    cost_hat = dist[ty*w+tx]
    # print(cost_hat)
    cost = int(input())

    scale = cost / cost_hat

    update(sy, sx, indices, scale)

    # printmat(hij)
    # printmat(vij)

    # break