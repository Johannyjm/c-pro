import random

a = [0] * 1000000
for i in range(1000000):
    a[i] = random.choice([0, 1])

# a = [1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1]
print(len(a))

rle = [[a[0], 1]]
for elem in a[1: ]:
    if rle[-1][0] == elem:
        rle[-1][1] += 1
    else:
        rle.append([elem, 1])

n = 3
id = 1
result = []
for elem, cnt in rle:
    if elem == 1 and cnt >= n:
        result += [id] * cnt
        id += 1
    else:
        result += [0] * cnt

print(a[: 20])
print(result[: 20])
print(len(result))