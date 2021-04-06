import math, cmath
n = int(input())
a, b = map(int, input().split())
c, d = map(int, input().split())

p0 = complex(a, b)
pn2 = complex(c, d)
o = (p0 + pn2) / 2
r = cmath.rect(1, 2*math.pi / n)

a = (p0-o) * r + o

print(a.real, a.imag)
