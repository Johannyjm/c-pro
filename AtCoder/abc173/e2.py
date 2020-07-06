n, k = map(int, input().split())
a = list(map(int, input().split()))

mul = 1
mod = 1000000007
aa = sorted(a, reverse=True, key=abs)
for i in range(k):
    mul *= aa[i]


res = mul
for i in range(k, n):
    mul = mul*aa[i]//aa[i-k]
    res = max(res, mul)

print(res%mod)