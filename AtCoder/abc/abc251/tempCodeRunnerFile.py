n, w = map(int, input().split())
a = list(map(int, input().split()))
flag = [0] * (w+1)

for i in range(n):
    if a[i] <= w: flag[a[i]] = 1
    
    for j in range(i+1, n):
        if a[i] + a[j] <= w: flag[a[i] + a[j]] = 1
        
        for k in range(j+1, n):
            if a[i] + a[j] + a[k] <= w: flag[a[i] + a[j] + a[k]] = 1

print(sum(flag))

