value_db = []
for i in range(51):
    for j in range(51):
        for k in range(51):

            value_db.append((i, j, k, 500*i + 100*j + 50*k))

a = int(input())
b = int(input())
c = int(input())
x = int(input())

res = 0

for i, j, k, val in value_db:
    if val != x: continue

    if i<=a and j<=b and k<=c:
        res += 1

print(res)