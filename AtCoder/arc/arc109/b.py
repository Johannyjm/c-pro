n = int(input())
d = n+1
s = n*(n+1)//2
s1 = (n+1)*(n+2)//2

fr = int((1+(8*n+9)**0.5)//2)
for i in range(fr+10000, max(0, fr-10000), -1):
    sm = i*(i+1) // 2

    if((s1-sm)>=s):
        print(n+1-i)
        exit()
