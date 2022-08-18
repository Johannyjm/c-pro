def main():
    n = int(input())

    res = 0
    for i in range(1, n+1):
        res += i*10000

    print(res // n)

if __name__ == '__main__':
    main()