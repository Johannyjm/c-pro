def main():
    n, m, x = map(int, input().split())

    c = [0] * n
    a = [[0]*m for _ in range(n)]

    for i in range(n):
        c[i], *a[i] = map(int, input().split())

    res = 1 << 60
    for i in range(1<<n):

        use = [False] * n
        for j in range(n):

            if (i & (1<<j)):
                use[j] = True

        b = [0] * m
        sm = 0
        for j in range(n):

            if use[j]:
                sm += c[j]
                for k in range(m):
                    b[k] += a[j][k]
        
        flg = True
        for j in range(m):
            if b[j] < x:
                flg = False
        
        if flg:
            res = min(res, sm)
    
    if res == 1 << 60:
        res = -1
    print(res)
        

if __name__ == '__main__':
    main()