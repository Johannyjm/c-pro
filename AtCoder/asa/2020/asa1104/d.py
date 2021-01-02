def f(x):
    ret = 0
    s = str(x)
    for c in s:
        ret += int(c)
    return ret


n = int(input())

res = []
for x in range(n-162, n):
    if(x <= 0): continue

    if(x + f(x) == n): res.append(x)

print(len(res))
for r in res: print(r)
