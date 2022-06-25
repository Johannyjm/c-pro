def main():
    n = int(input())
    a = list(map(int, input().split()))

    mx = 0
    res = 0
    for i in range(2, 1100):
        count = 0
        for e in a:
            if e%i == 0:
                count += 1
        
        if count > mx:
            mx = count
            res = i
            
    print(res)


if __name__ == '__main__':
    main()