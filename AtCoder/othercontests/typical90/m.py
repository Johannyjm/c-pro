from heapq import heapify, heappop, heappush

n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append((b, c))
    g[b].append((a, c))

def dijkstra(st):
    pq = []
    dist = [float('inf')] * n
    dist[st] = 0
    heappush(pq, (0, st))
    while(len(pq) > 0):
        d, v = heappop(pq)

        for ne in g[v]:
            if dist[ne[0]] > dist[v] + ne[1]:
                dist[ne[0]] = dist[v] + ne[1]
                heappush(pq, (dist[ne[0]], ne[0]))
    return dist

dist1 = dijkstra(0)
dist2 = dijkstra(n-1)

for i in range(n):
    print(dist1[i] + dist2[i])