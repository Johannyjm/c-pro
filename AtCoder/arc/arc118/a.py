# for t in range(1, 51):
a = []
if True:
    t = 3
    prev = (100+t) * 0 // 100
    for i in range(1, 30000):
        now = (100+t) * i // 100
        if now != prev + 1:
            # print(prev + 1)
            a.append(prev + 1)
        
        prev = now


for i in range(100):
    n = i+1
    if a[i] != (100*n + n*3 - 1) // 3:
        print(n, a[i] (100*n + n*3 - 1) // 3)