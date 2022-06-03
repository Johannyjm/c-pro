from collections import deque


def main():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]

    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1

        g[a].append(b)
    
    INF = 1001001001
    res = 0
    for st in range(n):
        q = deque()
        q.append(st)

        dist = [INF] * n
        dist[st] = 0

        while len(q) > 0:
            v = q.popleft()

            for nv in g[v]:
                if dist[nv] != INF: continue

                dist[nv] = dist[v] + 1
                q.append(nv)


        for d in dist:
            if d == INF: continue
            res += 1
    
    print(res)

if __name__ == '__main__':
    main()