n = int(input())
m = [0 for _ in range(n)]
d = [0 for _ in range(n)]

for i in range(n):
    m[i], d[i] = map(int, input().split('/'))
    m[i] -= 1
    d[i] -= 1

cal = [0 for _ in range(366)]
for i in range(366):
    if(i%7 == 0): cal[i] = 1
    if(i%7 == 6): cal[i] = 1

size = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
for i in range(n):
    idx = 0
    for j in range(m[i]):
        idx += size[j]
    idx += d[i]

    if(cal[idx] == 0): cal[idx] = 1
    else:
        drop = False
        while(cal[idx] == 1):
            idx += 1
            if(idx == 366):
                drop = True
                break
        
        if(not drop): cal[idx] = 1

res = 0
sm = 0
for c in cal:
    if(c==1): sm += 1
    else:
        res = max(res, sm)
        sm = 0

print(max(res, sm))