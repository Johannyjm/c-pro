from heapq import heappush, heappop

def main():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]

    for _ in range(m):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1

        g[a].append((b, c))
        g[b].append((a, c))

    INF = 1 << 60
    dist = [INF] * n
    dist[0] = 0

    pq = [(0, 0)]
    while len(pq) > 0:
        v, d = heappop(pq)

        if dist[v] != d:
            continue

        for nv, w in g[v]:
            if dist[nv] > dist[v] + w:
                dist[nv] = dist[v] + w

                heappush(pq, (dist[nv], nv))

    res = dist[-1]

    if res == INF:
        res = -1

    print(res)

if __name__ == '__main__':
    main()