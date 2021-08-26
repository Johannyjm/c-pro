def main():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]

    for _ in range(m):
        a, b = map(int, input().split())
        g[a].append(b)
        g[b].append(a)

    res = 0
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):

                planets = set()

                for nv in g[i]:
                    planets.add(nv)
                for nv in g[j]:
                    planets.add(nv)
                for nv in g[k]:
                    planets.add(nv)
                 
                res = max(res, len(planets))

                # res = max(res, len(set(g[i] + g[j] + g[k])))

    print(res)

if __name__ == '__main__':
    main()