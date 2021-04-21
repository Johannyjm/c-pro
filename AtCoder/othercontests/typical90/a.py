n, l = map(int, input().split())
k = int(input())
a = list(map(int, input().split()))

def check(m):
    now = 0
    cnt = 0
    for i in range(n):
        length = a[i] - now
        if length >= m:
            cnt += 1
            now = a[i]
    
    if l - now < m:
        cnt -= 1
    
    return cnt >= k

ok = 0
ng = l

while ng - ok > 1:
    mid = (ok + ng) // 2

    if check(mid):
        ok = mid
    else:
        ng = mid

print(ok)
