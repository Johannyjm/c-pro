l = int(input())
l -= 12

n = l+11

up = 1
base = l+11
for i in range(l):
    up *= base
    base -= 1
down = 1
for i in range(1, l+1): down *= i

print(up//down)