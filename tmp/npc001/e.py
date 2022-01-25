n, k = map(int, input().split())

res = 0
mod = 10**9 + 7

for i in range(k, n+1):
    fr = (0+i-1)*i//2
    to = (n-i+1 + n)*i//2


    res += to - fr + 1
    res %= mod

print(res)

