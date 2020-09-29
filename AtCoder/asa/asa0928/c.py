s = input()
n = len(s)
s = s[::-1]
res1 = 0
res2 = 0
for i in range(n):
    if(i%2 == 0): res2 += int(s[i])
    else: res1 += int(s[i])

print(res1, res2)