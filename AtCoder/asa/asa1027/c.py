n, a, b = map(int, input().split())
s = [int(input()) for _ in range(n)]

rng = max(s) - min(s)
if(rng == 0):
    print(-1)
    exit()
res1 = b/rng
res2 = a - sum(s) * res1 / n

print(res1, res2)