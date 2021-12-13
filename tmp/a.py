n, m, x = map(int, input().split())

c = [0] * n
a = [[0] * m for _ in range(n)] # a = [[0] * m] * n

for i in range(n):
    c[i], *a[i] = map(int, input().split())

res = 1001001001 # float('int')
for i in range(1 << n):
    
    use = [False] * n
    for j in range(n):
        
        if i & (1<<j):
            use[j] = True

    ability = [0] * m
    for j in range(n):
        
        if use[j]:
            for k in range(m):
                ability[k] += a[j][k]

    valid = True
    for k in range(m):
        if ability[k] < x:
            valid = False

    if not valid:
        continue

    cost = 0
    for j in range(n):
        
        if use[j]:
            cost += c[j]

    res = min(res, cost)

if res == 1001001001:
    res = -1

print(res)
