s = [input() for _ in range(3)]
t = input()

res = ''
for c in t:
    res += s[int(c) - 1]

print(res)