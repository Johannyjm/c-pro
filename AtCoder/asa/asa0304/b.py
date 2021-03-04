n, k = map(int, input().split())
a = list(map(int, input().split()))
cnt = dict()
for e in a:
    cnt[e] += 1

res = 0

for i in range(330000):
    if i in cnt:

