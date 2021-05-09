n, k = map(int, input().split())

res = n
for _ in range(k):
    if res % 200 == 0:
        res //= 200
    else:
        res = int(str(res) + "200")

print(res)