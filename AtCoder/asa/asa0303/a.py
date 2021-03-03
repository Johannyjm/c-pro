n = int(input())

def calc(x):
    ret = 0
    while(x):
        ret += x%10
        x //= 10
    return ret

res = 1001001001
for a in range(1, n):
    b = n - a
    sm = calc(a) + calc(b)

    res = min(res, sm)
print(res)
