from collections import deque


def main():
    n, m = map(int, input().split())

    g = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1

        g[a].append(b)
        g[b].append(a)
    
    res = [-1] * n

    INF = 1 << 60
    dist = [INF] * n
    dist[0] = 0

    q = deque()
    q.append(0)

    while len(q) != 0:
        v = q.popleft()

        for nv in g[v]:
            if dist[nv] != INF: continue

            dist[nv] = dist[v] + 1
            res[nv] = v+1

            q.append(nv)

    print("Yes")
    for i in range(1, n):
        print(res[i])

if __name__ == '__main__':
    main()