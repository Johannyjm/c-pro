h, w = map(int, input().split())

if h==1 or w==1:
    print(1)
    exit()

if h%2==1 and w%2==1:
    print((h*w + 1)//2)
else:
    print(h*w // 2)
