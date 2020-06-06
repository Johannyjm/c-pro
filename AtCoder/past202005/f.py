n = int(input())
a = [set(input()) for _ in range(n)]

res = ["" for _ in range(n)]
for i in range(n//2):
    if(a[i] & a[-i-1]):
        c = list(a[i] & a[-i-1])[0]
        res[-i-1]= c
        res[i] = c
    else:
        print(-1)
        exit()

if(n%2 == 1):
    res[n//2] = list(a[n//2])[0]

print(''.join(res))
