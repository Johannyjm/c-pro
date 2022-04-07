a, b, c, d = map(int, input().split())

count = [0] * 101
for i in range(a, b):
    count[i] += 1
for i in range(c, d):
    count[i] += 1

print(count.count(2))