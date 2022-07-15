def main():
    d, n = map(int, input().split())

    if d == 0:
        if n == 100:
            print(101)
        else:
            print(n)
    
    if d == 1:
        if n == 100:
            print(10100)
        else:
            print(n*100)
    
    if d == 2:
        if n == 100:
            print(1010000)
        else:
            print(n*10000)

if __name__ == '__main__':
    main()