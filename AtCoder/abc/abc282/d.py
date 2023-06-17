from collections import deque

n, m = map(int, input().split())
g = [[] for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1

    g[a].append(b)
    g[b].append(a)

color = [-1] * n # 2 colors 0/1
bias = 0

for i in range(n):
    
    if color[i] != -1:
        continue

    color[i] = bias + 1

    q = deque()
    q.append(i)

    while len(q) != 0:
        v = q.popleft()

        for nv in g[v]:
        
            if color[nv] != -1:
            
                if color[nv] == color[v]:
                    print(0)
                    exit()

                continue

            color[nv] = 1 - color[v] % 2 + bias

            q.append(nv)

    bias += 2

count_direct = [0] * n
for v in range(n):
    count = 0
    for nv in g[v]:
        
        if color[nv] != color[v]:
            count += 1

    count_direct[v] = count

count_color = dict()
for i in range(n):
    if color[i] in count_color:
        count_color[color[i]] += 1
    else:
        count_color[color[i]] = 1

res = 0
for v in range(n):
   res += n - count_color[color[v]] - count_direct[v] 

print(res//2)
