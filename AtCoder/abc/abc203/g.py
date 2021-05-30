import random
n = 800
k = 300

print(n, k)
for i in range(n):
    for j in range(n):
        print(random.randint(0, 1000000000), end=' ')
    print()