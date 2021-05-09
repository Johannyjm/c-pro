k, n, m = map(int, input().split())
a = list(map(int, input().split()))

b = []
err = []
# errceil = []
# errfloor = []
for i in range(k):
    b.append(m * a[i] // n)
    # print(m*e/n)
    fl = m*a[i]/n - m*a[i]//n
    err.append([fl, i])

rest = m - sum(b)

err.sort(reverse=True)
for i in range(rest):
    b[err[i][1]] += 1


print(*b)
