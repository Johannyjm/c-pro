def basen(x, d):
    ret = 0
    base = 1
    n = len(x)

    for i in reversed(range(n)):
        ret += int(x[i]) * base
        base *= d

    return ret

x = input()
m = int(input())

d = 0
for c in x:
    d = max(d, int(c))

if(basen(x, d+1) > m):
    print(0)
    exit()

if(len(x) == 1):
    print(1)
    exit()

ok = d+1
ng = 1<<61
while ng-ok > 1:
    mid = (ok + ng) // 2

    if(basen(x, mid) > m): ng = mid
    else: ok = mid

print(ok - d)
