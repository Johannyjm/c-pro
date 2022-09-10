def main():
    n, m = map(int, input().split())
    h = list(map(int, input().split()))
    g = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1

        g[a].append(b)
        g[b].append(a)
    
    res = 0
    for v in range(n):

        flg = True
        for nv in g[v]:
            if h[nv] >= h[v]: flg = False
        
        if flg: res += 1
    
    print(res)

if __name__ == '__main__':
    main()