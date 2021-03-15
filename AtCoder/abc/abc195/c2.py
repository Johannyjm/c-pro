n = int(input())

res = 0
for i in range(5):
    res += max(0, (n - pow(10, 3*(i+1))) + 1)

print(res)
