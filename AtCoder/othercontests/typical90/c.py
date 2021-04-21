from collections import deque
INF = 1001001001

n = int(input())
g = [[] for _ in range(n)]
for _ in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

def bfs(start):
    q = deque()
    q.append(start)
    ret = [INF] * n
    ret[start] = 0

    while(len(q) > 0):
        v = q.popleft()
        for nv in g[v]:
            if ret[nv] != INF: continue

            ret[nv] = ret[v] + 1
            q.append(nv)
    
    return ret



dist = bfs(0)
idx = dist.index(max(dist))

dist2 = bfs(idx)

print(max(dist2) + 1)

