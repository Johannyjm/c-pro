import sys
sys.setrecursionlimit(10**6)

def main():

    def dfs(v):
        seen[v] = True
        for nv in g[v]:
            if seen[nv]: continue

            dfs(nv)


    n, m = map(int, input().split())

    g = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(lambda x: int(x)-1, input().split())
        g[a].append(b)
        g[b].append(a)
    
    res = 0
    seen = [False] * n
    for i in range(n):
        if seen[i]: continue

        dfs(i)
        res += 1
    
    print(res-1)

if __name__ == '__main__':
    main()