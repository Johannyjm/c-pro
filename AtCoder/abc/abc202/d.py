import math
def comb(n,k):
    # print(n, k)
    k = min(k, n-k)
    return math.factorial(n) // (math.factorial(n - k) * math.factorial(k))

a, b, k = map(int, input().split())

cnt = 0
now = 0
while cnt <= min(a, b):
    now += comb(a, cnt) * comb(b, cnt)
    if now >= k: break
    cnt += 1


print(cnt)