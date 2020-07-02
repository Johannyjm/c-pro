n = int(input())

f = [0] * (n+1)

for i in range(1, n+1):
    for j in range(i, n+1, i):
        # print(i, j)
        f[j] += 1

res = 0
for i in range(1, n+1):
    res += i * f[i]

print(res)