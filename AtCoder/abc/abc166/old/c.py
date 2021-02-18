n, m = map(int, input().split())
h = list(map(int, input().split()))

g = [[] for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

res = 0

for i in range(n):
    mx = 0
    for nv in g[i]:
        mx = max(mx, h[nv])

    if h[i] > mx: res += 1

print(res)
