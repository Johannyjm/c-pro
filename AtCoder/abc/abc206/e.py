from math import gcd
# l = 3
# r = 7
l, r = map(int, input().split())
def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

res = 0
for x in range(l, r+1):
    # print(x, factorization(x))
    sm = 0
    for y in range(l, r+1):
        g = gcd(x, y)
        if g!=1 and x//g!=1 and y//g!=1:
            # print(x, y, g)
            sm += 1
    print(x, sm)
    res += sm
print(res)