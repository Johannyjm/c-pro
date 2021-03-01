n = int(input())
cnt = 0
a = 2
while True:
    b = 2
    while True:
        if a**b > n:
            break

        else:
            cnt += 1
            # print(a, b)

        b += 1
    
    if a*a > n: break
    a += 1

print(n - cnt)
