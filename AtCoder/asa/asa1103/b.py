n = int(input())

res = [0] * 6
for _ in range(n):
    mx, mn = map(float, input().split())

    if(mx>=35): res[0] += 1
    if(30<=mx<35): res[1] += 1
    if(25<=mx<30): res[2] += 1
    if(mn>=25): res[3] += 1
    if(mn<0 and mx>=0): res[4] += 1
    if(mx<0): res[5] += 1

print(*res)
