from collections import defaultdict
n, k = map(int, input().split())
a = list(map(int, input().split()))

res = 0
cnt = defaultdict(int)
for e in a:
    cnt[e] = cnt[e-k] + 1
    res = max(res, cnt[e])

if res == 1: res = -1
print(res)