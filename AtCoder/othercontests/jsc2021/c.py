a, b = map(int, input().split())

res = 1
for c in range(2, b+1):
    now = c
    cnt = 0
    while True:
        if a <= now <= b:
            cnt += 1
        
        now += c
        if now > b: break
    
    if cnt > 1:
        res = max(res, c)


print(res)