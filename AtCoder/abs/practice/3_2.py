n = int(input())
a = list(map(int, input().split()))

def calc(num):
    ret = 0
    while True:
        if num % 2 == 0:
            ret += 1
            num //= 2
        else:
            break
    return ret

res = 1001001001
for i in range(n):
    res = min(res, calc(a[i]))

print(res)