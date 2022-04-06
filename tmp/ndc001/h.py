n = int(input())
s = list(map(int, input().split()))
t = list(map(int, input().split()))

res = [e for e in t]
for i in range(n):
    res[i+1] = min(res[i+1], res[i] + s[i])
res[0] = min(res[0], res[n-1] + s[n-1])

print(*res, sep='\n')