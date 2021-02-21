n, k = map(int, input().split())

def g1(x):
    ret = sorted(str(x), reverse=True)
    return int(''.join(ret))

def g2(x):
    ret = sorted(str(x))
    return int(''.join(ret))

def f(x):
    return g1(x) - g2(x)


res = n
for _ in range(k):
    res = f(res)

print(res)
