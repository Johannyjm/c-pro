from collections import deque

def main():
    n = int(input())
    g = [[] for _ in range(n)]

    for _ in range(n - 1):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1

        g[a].append([b, c])
        g[b].append([a, c])
    
    q = deque()
    q.append(0)

    dist = [-1] * n
    dist[0] = 0 
    
    while len(q) > 0:
        v = q.popleft()

        for nv, nw in g[v]:
            
            if dist[nv] == -1:

                dist[nv] = dist[v] ^ nw
                q.append(nv)
    
    mod = 1000000007
    res = 0

    for i in range(60):
        count = [0] * 2

        for j in range(n):

            count[(dist[j] >> i) & 1] += 1
        
        res += 2**i * count[0] * count[1]
    
    print(res % mod)

if __name__ == '__main__':
    main()