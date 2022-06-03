def main():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    friend = [set() for _ in range(n)]
    
    for _ in range(m):
        a, b = map(int, input().split())

        a -= 1
        b -= 1
        g[a].append(b)
        g[b].append(a)
        friend[a].add(b)
        friend[b].add(a)
    
    res = [0] * n
    for v in range(n):
        count = 0
        counted = set()
        for nv in g[v]:
            for nnv in g[nv]:
                if nnv == v: continue
                if v in friend[nnv]: continue
                if nnv in counted: continue

                count += 1
                counted.add(nnv)
                
        res[v] = count
    
    print(*res, sep='\n')


if __name__ == '__main__':
    main()