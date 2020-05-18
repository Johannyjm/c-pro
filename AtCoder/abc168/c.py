def r2d(d):
    return d*360/2/math.pi

import math
a, b, h, m = map(int, input().split())
short = (h * (360 / 12)) + m * 1/2;

long = m * (360 / 60);

ang = abs(long - short);

ang = min(ang, (360 - ang))

res2 = a**2 + b**2 -2*a*b*math.cos(2*math.pi * (ang/360))

print(res2 ** 0.5)