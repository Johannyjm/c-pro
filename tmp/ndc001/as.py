s = input()
res = 0
for c in s:
    if c == '+': res += 1
    else: res -= 1
print(res)