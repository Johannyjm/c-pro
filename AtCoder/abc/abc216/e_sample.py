import random
n, k, amx = map(int, input().split())
a = []
for i in range(n):
    a.append(random.randint(1, amx))

print(n, k)
print(*a)

