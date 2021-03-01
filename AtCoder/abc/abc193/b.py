n = int(input())
res = 1001001001
for i in range(n):
    a, p, x = map(int, input().split())
    x -= a
    if(x > 0):
        res = min(res, p)

if(res == 1001001001): res = -1
print(res)