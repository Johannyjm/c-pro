def f(x, y, z):
    return x*x + y*y + z*z + x*y + y*z + z*x

n = int(input())

cnt = {}
for x in range(1, 101):
    for y in range(1, 101):
        if(f(x, y, 1) > n): break
        for z in range(1, 101):
            if(f(x, y, z) > n): break
            
            val = f(x, y, z)

            if(cnt.get(val) is None): cnt[val] = 1
            else: cnt[val] += 1

for i in range(1, n+1):
    if(cnt.get(i) is None): print(0)
    else: print(cnt[i])