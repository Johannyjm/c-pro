n = int(input())
s = [list(input()) for _ in range(n)]

cnt = 1001001001
for i in range(n):
    for j in range(n):
        l = i
        r = i + 6
        if r >= n: continue

        cnt = min(cnt, s[i][l: r].count('.')

t = [[''] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        t[i][j] = s[j][i]

for i in range(n):
    for j in range(n):
        l = i
        r = i + 6
        if r >= n: continue

        cnt = min(cnt, t[i][l: r].count('.')

for i in range(n):
    for j in range(n):
        
        if i+5 >= n or j+5 >= n: continue
        for k in range(6):
            
