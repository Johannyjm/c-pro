n = int(input())
apx = [list(map(int, input().split())) for _ in range(n)]

res = 1 << 60
for i in range(n):
    if apx[2] - apx[0] > 0:
        res = min(res, apx[1])

if res == 1 << 60:
    res = -1
print(res)
