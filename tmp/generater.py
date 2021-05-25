import numpy as np
n = 200000
k = 5
l = -1000000000
r = 1000000000

# embed = True
# now = 2021
# print(n, k)
# for i in range(n):
#     if embed and i%5000 == 0:
#         print(now, end=' ')
#         now += k
#     else:
#         print(int(np.random.uniform(l, r+1)), end=' ')
# print()


print(200000, 7)
now = 500000000
for i in range(0, 90000, 7):
    print(now + i, end=" ")
now += 340000000
for i in range(0, 60000, 7):
    print(now + i, end=" ")
now -= 606000000
for i in range(0, 50000, 7):
    print(now + i, end=" ")
print()