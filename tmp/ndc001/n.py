n = int(input())
r = list(sorted([int(input()) for _ in range(n)]))

pi = 3.1415926535897932384626
r = list(reversed(r))
res = pi * r[0] * r[0]

for i in range(1, n):
    if i % 2 == 1: res -= pi * r[i] * r[i]
    else: res += pi * r[i] * r[i]

print(res)
