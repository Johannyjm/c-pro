def main():
    n = int(input())
    a = list(map(int, input().split()))

    res = 0
    for e in a:
        e %= 6
        if e in (2, 4):
            res += 1
        if e == 5:
            res += 2
        if e == 0:
            res += 3
    
    print(res)

if __name__ == '__main__':
    main()