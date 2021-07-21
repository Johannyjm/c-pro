while True:
    n, x = map(int, input().split())

    if n == 0: break
    n += 1
    res = 0
    for a in range(1, n):
        for b in range(a+1, n):
            for c in range(b+1, n):
                
                if a + b + c == x:
                    # print(a, b, c)
                    res += 1
    print(res)