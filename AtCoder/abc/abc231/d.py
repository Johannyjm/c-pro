def main():
    n, m = map(int, input().split())

    g = [set() for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        g[a].add(b)
        g[b].add(a)
    
    for v in range(n):
        if len(g[v]) > 2:
            print("No")
            exit()
    
    print("Yes")

if __name__ == '__main__':
    main()