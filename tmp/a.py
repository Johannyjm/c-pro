from collections import deque

n = int(input())
s = [input() for _ in range(n)]
g = [[] for _ in range(n)]

for i in range(n):
    if s[i].split()[1] == '0': continue

    for j in s[i].split()[2: ]:
        g[i].append(int(j)-1)
#print(g)

# enqueue -> deque().append()
# dequeue -> deque().popleft()

q = deque()
q.append(0)
INF = float('inf')
dist = [INF for _ in range(n)]
dist[0] = 0

while len(q) > 0:
    v = q.popleft()

    for nv in g[v]:
        if dist[nv] != INF: continue

        dist[nv] = dist[v] + 1
        q.append(nv)

for i in range(n):
    if dist[i] != INF: print(i+1, dist[i])
    else: print(i+1, -1)




