n, m = map(int, input().split())

for y in range(n+1):
    val = m - 2*n - y
    if(val < 0): continue
    if(val % 2 == 1): continue
    z = val // 2
    x = n - y - z
    if(x < 0): continue
    print(x, y, z)
    exit()

print(-1, -1, -1)