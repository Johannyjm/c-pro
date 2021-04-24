h, w = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(h)]

smh = [0] * w
smw = [0] * h

for i in range(h):
    smw[i] = sum(a[i])

for j in range(w):
    sm = 0
    for i in range(h):
        sm += a[i][j]
    smh[j] = sm

for i in range(h):
    for j in range(w):
        print(smw[i] + smh[j] - a[i][j], end=' ')
    print()