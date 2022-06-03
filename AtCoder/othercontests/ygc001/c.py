from collections import deque

def main():
    n, Q = map(int, input().split())
    g = [[] for _ in range(n)]

    for _ in range(n-1):
        a, b = map(int, input().split())

        a -= 1
        b -= 1
        g[a].append(b)
        g[b].append(a)
    
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
        
    
    res = [''] * Q
    for i in range(Q):
        c, d = map(int, input().split())

        c -= 1
        d -= 1

        if dist[c]%2 == dist[d]%2:
            res[i] = 'Town'
        else:
            res[i] = 'Road'
        
    print(*res, sep='\n')



if __name__ == '__main__':
    main()