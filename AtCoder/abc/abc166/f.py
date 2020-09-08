n, a, b, c = map(int, input().split())
res = []
for i in range(n):
    s = input()

    if(s == "AB"):
        if(a>b):
            b += 1
            a -= 1
            res.append("B")
        else:
            a += 1
            b -= 1
            res.append("A")
    if(s == "AC"):
        if(a<c):
            a += 1
            c -= 1
            res.append("A")
        else:
            a -= 1
            c += 1
            res.append("C")
    else:
        if(b<c):
            c -= 1
            b += 1
            res.append("B")
        else:
            c += 1
            b -= 1
            res. append("C")
    
    if(a<0 or b<0 or c < 0): 
        print("No")
        exit()

print("Yes")
for r in res:
    print(r)