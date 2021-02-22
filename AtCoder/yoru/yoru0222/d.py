n = int(input())
s = input()

cnt = 0
for c in s:
    if c == '.': cnt += 1

res = cnt
for c in s:
    if c == '#':
        cnt += 1
    else:
        cnt -= 1
    res = min(res, cnt)

print(res)
