n = int(input())
a = list(map(int, input().split()))
res = 0
for i in range(n - 2):
    if a[i] <= a[i+1] <= a[i+2] or a[i] >= a[i+1] >= a[i+2]:
        res += 1

print(res)