x = int(input())

m = 100
res = 0

while(True):
    m *= 1.01
    m = int(m)
    res += 1

    if(m >= x): break

print(res)