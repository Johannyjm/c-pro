n, x, m = map(int, input().split())

prev = x
print(x)
for i in range(100):
    a = prev*prev % m
    print(a)
    prev = a