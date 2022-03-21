def main():
    # x = int(input())
    x = 1888

    an = set()
    for i in range(100):
        an.add(i)
    
    for i in range(1, 10):
        for j in range(3, 18):
            an.add(int(str(i) * j))
    
    for d in range(3, 18):
        for st in range(1, 10):
            for k in range(-10, 10):

                num = ''
                now = 0
                for i in range(d):
                    now = st + k * i
                    if now > 9 or now < 0: break
                    num += str(now)
                
                an.add(int(num))

    an = list(an)
    an.sort()
    print(an)

    oth = list(map(int, input().split()))

    print(set(an) ^ set(oth))

    for res in an:
        if res >= x:
            print(res)
            exit()

if __name__ == '__main__':
    main()