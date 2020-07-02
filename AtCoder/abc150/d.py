n, m = map(int, input().split())
a = list(map(int, input().split()))

mp = dict()
for i in range(n):
    by = 0.5
    while(a[i]*by <= m):
        if(mp.get(int(a[i]*by)) is None): mp[int(a[i]*by)] = 1
        else: mp[int(a[i]*by)] += 1
        print(a[i], int(a[i]*by))
        by += 1

print(mp)