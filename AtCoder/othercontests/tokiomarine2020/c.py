n, k = map(int, input().split())
a = list(map(int, input().split()))

for c in range(200):
    if(c == k): break
    tmp = [0 for _ in range(n)]
    for i in range(n):
        l = max(i - a[i], 0)
        r = min(i + a[i], n-1)
        
        for j in range(l, r+1):
            tmp[j] += 1
    for j in range(n):
        a[j] = tmp[j]

print(*a)