n = int(input())

imos = [[0] * 1100 for _ in range(1100)]
for _ in range(n):
    a, b, c, d = map(int, input().split())

    imos[a][b] += 1
    imos[a][d] -= 1
    imos[c][b] -= 1
    imos[c][d] += 1

for i in range(1010):
    for j in range(1010):
        imos[i][j+1] += imos[i][j]
for j in range(1010):
    for i in range(1010):
        imos[i+1][j] += imos[i][j]

res = [0] * (n+1)
for i in range(1010):
    for j in range(1010):
        res[imos[i][j]] += 1


# for i in range(100):
#     for j in range(100): print(imos[i][j], end=" ")
#     print()

for i in range(1, n+1):
    print(res[i])