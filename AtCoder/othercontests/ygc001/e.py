from collections import deque

def main():
    n, x, y = map(int, input().split())
    x -= 1
    y -= 1
    g = [[] for _ in range(n)]
    for v in range(n-1):
        g[v].append(v+1)
        g[v+1].append(v)
    
    g[x].append(y)
    g[y].append(x)

    q = deque()
    q.append(0)

    INF = 1001001001
    dist = [INF] * n
    dist[0] = 0

    while len(q) > 0:
        v = q.popleft()

        for nv in g[v]:
            if dist[nv] != INF: continue

            dist[nv] = dist[v] + 1
            q.append(nv)
    
    dist_count = dict()
    for d in dist:
        if d not in dist_count:
            dist_count[d] = 1
        else:
            dist_count[d] += 1
    
    res = [0] * (n-1)
    for k in range(1, n):
        count = 0
        for d in range(n):
            if d+k not in dist_count: break

            count += dist_count[d+k]

        res[k-1] = count
    
    print(*res, sep='\n')

if __name__ == '__main__':
    main()