n = int(input())
x = list(map(int, input().split()))

m = 0
e = 0
t = -1
for el in x:
    m += abs(el)
    e += el*el
    t = max(t, abs(el))
e **= 0.5

print(m)
print(e)
print(t)