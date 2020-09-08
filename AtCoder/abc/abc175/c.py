import math
x, k, d = map(int, input().split())

if(abs(x) - k*d >= 0):
    print(abs(x) - k*d)
else:
    num = abs(x) // d
    rest = abs(x) % d

    if(num % 2 == 0):
        if(k%2==0): print(rest)
        else: print(d-rest)
    else:
        if(k%2==1): print(rest)
        else: print(d-rest)