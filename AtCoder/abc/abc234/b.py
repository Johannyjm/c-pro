n = int(input())

xy = [list(map(int, input().split())) for _ in range(n)]

d2max = 0

for i in range(n):
    for j in range(n):
        x1, y1 = xy[i]
        x2, y2 = xy[j]

        d2 = (x1-x2)**2 + (y1-y2)**2

        d2max = max(d2max, d2)

print(d2max ** .5)
