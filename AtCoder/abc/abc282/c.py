n = int(input())
s = input()

res = ""
inside = False
for i in range(n):
    if s[i] not in ('"', ','):
        res += s[i]
        continue

    if s[i] == '"':
        inside = not inside
        res += s[i]

    if s[i] == ',':
        if inside:
            res += ','
        else:
            res += '.'
print(res)
