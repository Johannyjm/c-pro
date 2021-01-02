import re
s = input().split() #list(map(lambda x: x.replace('*', '.'), input().split()))

n = int(input())
flg = [False for _ in range(len(s))]
for i in range(n):
    t = '^' + input().replace('*', '.') + '$'
    
    for j in range(len(s)):
        if(len(re.findall(t, s[j])) > 0): flg[j] = True

res = ['' for _ in range(len(s))]
for i in range(len(s)):
    if(flg[i]): res[i] = '*' * len(s[i])
    else: res[i] = s[i]
    
print(*res)