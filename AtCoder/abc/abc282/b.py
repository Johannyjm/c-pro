n, m = map(int, input().split())

s = [input() for _ in range(n)]

res = 0
for i in range(n):
    for j in range(i+1, n):

        flg = True

        for k in range(m):
            
            if s[i][k] == 'x' and s[j][k] == 'x':
                flg = False

        if flg:
            res += 1

print(res)
