s = [0] * 3
for i in range(3): s[i] = input()
t = input()
res = ''
for c in t:
    res += s[int(c)-1]
print(res)