def basen(x, d):
    ret = 0
    base = 1
    n = len(x)

    for i in reversed(range(n)):
        if(ret > m or base > m): return False
        ret += int(x[i]) * base
        base *= d

    return ret

x = input()
m = int(input())

d = 0
for c in x:
    d = max(d, int(c))

# print(d, basen(x, d+1))
if(not basen(x, d+1) or basen(x, d+1)>m):
    print(0)
    exit()

if(len(x) == 1):
    print(1)
    exit()

ok = d+1
ng = 1<<61
while ng-ok > 1:
    mid = (ok + ng) // 2
    val = basen(x, mid)
    # print(ok, mid, ng, val)

    if(not val or val>m): ng = mid
    else: ok = mid

print(ok-d)
