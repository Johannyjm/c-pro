from itertools import accumulate
n, k = map(int, input().split())
a = list(map(int, input().split()))
sm = list(accumulate(a, initial=0))

b = []
for l in range(n-1):
    for r in range(l, n):
        b.append(sm[r+1] - sm[l])

# print(b)

b.sort(reverse=True)

bits = [[0] * 31 for _ in range(len(b))]
for i in range(len(b)):
    num = b[i]
    d = 1
    while(num):
        bits[i][31 - d] = num % 2
        num //= 2
        d += 1

mxd = -1
for i in range(31):
    cnt = 0
    for j in range(len(b)):
        cnt += bits[j][i]
    if cnt >= k:
        mxd = i
        break

if mxd == -1:
    print(0)
    exit()

cand = []
for i in range(len(b)):
    if bits[i][mxd] == 1:
        cand.append(i)

resbit = [0] * 31
resbit[mxd] = 1

for dig in range(mxd, 31):
    for i in range(dig, 31):
        cnt = 0
        for j in cand:
            cnt += bits[j][i]

        if cnt >= k:
            resbit[i] = 1

            tmp = []
            for idx in cand:
                if bits[idx][i] == 1:
                    tmp.append(idx)

            cand = tmp

res = 0
for i in range(31):
    res += resbit[i] * (1<<(31-i-1))

print(res)
