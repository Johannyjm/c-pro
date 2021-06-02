a, b, x = map(int, input().split())

def price_of(n):
    return a*n + b*len(str(n))

ok = 0
ng = 10**9+1

while ng-ok > 1:
    mid = (ng+ok) // 2

    if price_of(mid) <= x:
        ok = mid
    else:
        ng = mid
        
print(ok)