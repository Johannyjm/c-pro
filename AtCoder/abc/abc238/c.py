n = int(input())
mod = 998244353
d = len(str(n))

res = 0
now = 9
for i in range(1, d):
    res += (1 + now) * now // 2
    res %= mod
    now *= 10

remain = n - 10**(d-1)

res += (remain + 2) * (remain +  1) // 2

print(res % mod)
