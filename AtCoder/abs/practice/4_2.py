a = int(input())
b = int(input())
c = int(input())
x = int(input())

res = 0
for i in range(a+1):
    for j in range(b+1):

        total = 500*i + 100*j

        if total > x: continue

        if (x-total)%50 == 0 and (x-total)//50 <= c:
            res += 1

print(res)

