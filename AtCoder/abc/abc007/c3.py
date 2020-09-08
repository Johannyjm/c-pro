from collections import deque
n, m = map(int, input().split())

g = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1

    g[a].append(b)
    g[b].append(a)

INF = 1001001001
dist = [INF for _ in range(n)]
dist[0] = 0
q = deque()
q.append(0)
edge_from = {}

while(len(q) > 0):
    v = q.popleft()

    for nv in g[v]:

        if(dist[nv] != INF): continue
        dist[nv] = dist[v] + 1
        edge_from[nv] = v
        q.append(nv)

print("Yes")
for i in range(1, n): print(edge_from[i] + 1)