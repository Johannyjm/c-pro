n = int(input())
a = list(map(int, input().split()))

pre = [[0] * 440 for _ in range(440)]
for i in range(-220, 220):
    for j in range(-220, 220):
        val = (i-j) * (i-j)
        pre[i+220][j+220] = val

cnt = [0] * 440
for e in a:
    cnt[e+220] += 1

res = 0
for i in range(-220, 220):
    for j in range(-220, 220):
        if i >= j: continue
        res += pre[i+220][j+220] * cnt[i+220] * cnt[j+220]

print(res)
