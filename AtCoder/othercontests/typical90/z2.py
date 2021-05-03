from collections import deque
n = int(input())
g = [[] for _ in range(n)]
for _ in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

res = set()
seen = [False] * n
q = deque()
for v in range(n):
    if len(g[v]) == 1:
        res.add(v)
        q.append(v)
        seen[v] = True

if len(res) >= n//2:
    res = list(map(lambda x: x+1, res))
    print(*res[: n//2])
    exit()

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