def check(X):
    R = r - X
    B = b - X

    if R // (x-1) + B // (y-1) >= X:
        return True
    else:
        return False

r, b = map(int, input().split())
x, y = map(int, input().split())

ok = -1
ng = 1 << 60

while ng - ok > 1:
    mid = (ng + ok) // 2

    if check(mid):
        ok = mid
    else:
        ng = mid

print(ok)