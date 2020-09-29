a, k = map(int, input().split())
if(k == 0):
    print(2000000000000-a)
    exit()
res = 1
while(a < 2000000000000):
    a += 1+k*a
    res += 1
print(res-1)