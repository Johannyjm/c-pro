a, r, n = map(int, input().split())

if(r == 1): print(a)

else:
    res = a
    flg = False
    for _ in range(n-1):
        res *= r

        if(res > 10**9):
            flg = True
            break
    
    if(flg): print('large')
    else: print(res)