def digit_sum(n):
    if(n<10): return (n, 0)
    if(n==10): return (1, 1)

    ret = 0
    di = 0
    while(n != 0):
        di += n%10
        n //= 10
        ret += 1
    
    ret -= 1

    if(di < 10): return (di, ret)

    fi, sec = digit_sum(di)

    return fi, sec+ret


m = int(input())
dc = [list(map(int, input().split())) for _ in range(m)]

mul = 0
res = m-1
for d, c in dc:
    for i in range(c):
        print(d,end='')
    mul += d*c
    res += c-1
print()

fi, se = digit_sum(mul)
print(digit_sum(9999999999))
print(res+se)
