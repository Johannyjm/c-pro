n, d = map(int, input().split())

def dist(p, q): return (p*p + q*q) ** 0.5

xy = [list(map(int, input().split())) for _ in range(n)]
res = 0
for x, y in xy:
    if(dist(x, y) <= d): res += 1

print(res)