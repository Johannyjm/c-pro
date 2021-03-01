n = int(input())
cnt = set()
a = 2
while True:
    b = 2
    while True:
        if a**b > n:
            break

        else:
            cnt.add(a**b)

        b += 1
    
    if a*a > n: break
    a += 1

print(n - len(cnt))
