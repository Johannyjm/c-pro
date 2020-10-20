n = int(input())
x = list(map(int, input().split()))

res1 = 0
res3 = -1
for e in x:
    res1 += abs(e)
    res3 = max(res3, abs(e))

res2 = 0
for e in x:
    res2 += e * e

res2 **= 0.5

print(res1)
print(res2)
print(res3)