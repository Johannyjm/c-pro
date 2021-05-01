n, d, h = map(int, input().split())
dh = [list(map(int, input().split())) for _ in range(n)]

ok = 1000.
ng = 0.

def check(m):
    for i in range(n):
        if((h-m)/d < (dh[i][1]-m)/dh[i][0]): return False
    return True

for _ in range(1000):
    mid = (ok + ng) / 2
    if(check(mid)): ok = mid
    else: ng = mid

print(ok)