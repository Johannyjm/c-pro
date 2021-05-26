import sys
sys.setrecursionlimit(10**6)

def dfs(v, seen, group):
    seen[v] = True
    groups[v] = group
    for nv in g[v]:
        if seen[nv]: continue
        dfs(nv, seen, group)

n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

# print(g)

groups = [-1] * n
group = 0
for st in range(n):
    if groups[st] != -1: continue
    seen = [False] * n
    dfs(st, seen, group)
    group += 1

print(max(groups)) 
