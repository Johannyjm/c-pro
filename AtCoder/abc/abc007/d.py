n = int(input())

res = 0
for i in range(1, n+1):
    if('4' in str(i) or '9' in str(i)): res += 1

print(res)
