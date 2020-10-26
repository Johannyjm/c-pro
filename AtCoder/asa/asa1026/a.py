n = 12
s = list(input() for _ in range(n))

res = 0
for st in s:
    if('r' in st): res += 1

print(res)