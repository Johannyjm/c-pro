n, m = map(int, input().split())
sc = [list(map(int, input().split())) for _ in range(m)]

for i in range(1000):
    num = str(i)
    d = len(num)
    if(d != n): continue
    
    valid = True
    for s, c in sc:
        s -= 1
        if(num[s] != str(c)):
            valid = False
            break
    
    if(valid):
        print(num)
        exit()
print(-1)