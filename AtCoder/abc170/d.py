n = int(input())
a = list(map(int, input().split()))

mp = {}
for i in range(n):
    if(mp.get(a[i]) is None): mp[a[i]] = 1
    else: mp[a[i]] += 1

mx = max(a)

res = 0
for i in range(n):
    if(mp[a[i]] > 2): continue
    
    num = a[i]

    flg = False
    for j in range(2, 100000):
        if(mp.get(num*j) is None): pass
        elif(mp[num*j] > 0): break

        if(num*j > mx):
            print(num)
            flg = True
            break
    
    if(flg): res += 1

print(res)

