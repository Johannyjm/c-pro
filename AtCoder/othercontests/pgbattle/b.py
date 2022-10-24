from math import sqrt


w, h, t = map(int, input().split())
sx, sy = map(int, input().split())
gx, gy = map(int, input().split())

a = gx - sx - w
b = gy - sy - h

# if a**2 + b**2 > t**2:
#     print(0)
#     exit()
# if a**2 + b**2 == t**2:
#     print(1)

def is_squared(x):
    r = int(sqrt(x))    
    return x in ((r-1)**2, r**2, (r+1)**2)


res = 0
for i in range(220000):
    right = t**2 - (a + w*i)**2
    if right >= 0:
        if is_squared(right):
            root = int(sqrt(right))
            root -= b
            if root >= 0:
                if root % h == 0:
                    res += 1

    right = t**2 - (a - w*i)**2
    if right >= 0:
        if is_squared(right):
            root = int(sqrt(right))
            root -= b
            if root >= 0:
                if root % h == 0:
                    res += 1
print(res)