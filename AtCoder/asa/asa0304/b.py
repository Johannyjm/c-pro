n, k = map(int, input().split())
a = list(map(int, input().split()))

cnt = dict()
for e in a:
    if e in cnt: cnt[e] += 1
    else: cnt[e] = 1

res = 0
rest = k
for i in range(330000):
    if i not in cnt: break

    res += min(rest, cnt[i])
    rest = min(rest, cnt[i])


print(res)

