from math import gcd
a, b = map(int, input().split())

res = a * b // gcd(a, b)

if res > 10**18: print("Large")
else: print(res)
