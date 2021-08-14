n, d = map(int, input().split())
xy = [list(map(int, input().split())) for _ in range(n)]

res = 0
for i in range(n):
    if xy[i][0] ** 2 + xy[i][1] ** 2 <= d ** 2:
        res += 1

print(res)