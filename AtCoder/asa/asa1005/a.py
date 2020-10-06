n = 12
s = [input() for _ in range(n)]

res = 0
for s_ in s:
    if('r' in s_): res += 1

print(res)