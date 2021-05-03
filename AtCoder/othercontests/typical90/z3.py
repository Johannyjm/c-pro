import sys
sys.setrecursionlimit(10**6)

n = int(input())
g = [[] for _ in range(n)]

for _ in range(n-1):
    a, b = map(lambda x: int(x)-1, input().split())
    g[a].append(b)
    g[b].append(a)

color = [-1] * n
color[0] = 0

def dfs(v):
    for nv in g[v]:
        if color[nv] != -1:
            continue

        color[nv] = 1 - color[v]
        dfs(nv)
dfs(0)
# print(color)
c = 0
if sum(color) >= n//2:
    c = 1

res = []
for i in range(n):
    if color[i] == c:
        res.append(i+1)
print(*res[: n//2])