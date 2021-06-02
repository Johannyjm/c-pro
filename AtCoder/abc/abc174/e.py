def check(l):
    cnt = 0
    for i in range(n):
        cnt += (a[i]-1)//l
    
    return cnt <= k

n, k = map(int, input().split())
a = list(map(int, input().split()))

ok = 10**9+1
ng = 0

while ok-ng > 1:
    mid = (ok + ng) // 2

    if check(mid):
        ok = mid
    else:
        ng = mid

print(ok)