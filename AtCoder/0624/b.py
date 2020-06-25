s = input().split('+')
# print(s)

res = 0
for c in s:
    if('0' not in c): res += 1

print(res)