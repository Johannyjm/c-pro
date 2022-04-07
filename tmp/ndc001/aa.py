n, a, b = map(int, input().split())
res = n // (a+b) * a
rem = n % (a+b)
res += min(a, rem)
print(res)