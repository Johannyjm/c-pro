s = input()
res = 0
for i in range(len(s)):
    if i % 2 == 0:
        res += int(s[i])
    else:
        res += 