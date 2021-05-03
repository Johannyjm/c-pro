from collections import deque
n = int(input())
g = [[] for _ in range(n)]
for _ in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

mn_d = 1001001001
mn_v = -1
for i in range(n):
    if len(g[i]) < mn_d:
        mn_d = len(g[i])
        mn_v = i

res = set()
seen = [False] * n
seen[mn_v] = True
q = deque()
q.append(mn_v)

while(len(q) > 0):
    v = q.popleft()
    flg = True
    for nv in g[v]:
        if nv in res:
            flg = False
        if seen[nv]:
            continue
        
        seen[nv] = True
        q.append(nv)
    
    if flg:
        res.add(v)

res = list(map(lambda x: x+1, res))
print(*res[: n//2])

