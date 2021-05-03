from math import gcd
a, b, c = map(int, input().split())

g = gcd(a, gcd(b, c))
a //= g
b //= g
c //= g
print(a+b+c - 3)