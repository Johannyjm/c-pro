n = int(input())
a = list(map(int, input().split()))

res = float('inf')
for i in range(1<<(n-1)):
    divide = [False] * (n-1)
    for j in range(n-1):
        if i & (1<<j):
            divide[j] = True

    ored = []
    now = a[0]
    for j in range(n-1):
        if divide[j]:
            ored.append(now)
            now = a[j+1]
        else:
            now |= a[j+1]
    ored.append(now)

    xored = 0
    for e in ored:
        xored ^= e

    res = min(res, xored)

print(res)
