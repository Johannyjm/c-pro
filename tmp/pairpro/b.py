n, m = map(int, input().split())

imos = [0] * 110000
for i in range(m):
    l, r = map(int, input().split())

    imos[l] += 1
    imos[r+1] -= 1

for i in range(105000):
    imos[i+1] += imos[i]

res = 0
for cnt in imos:
    if cnt == m:
        res += 1

# print(imos[: 10])

print(res)
