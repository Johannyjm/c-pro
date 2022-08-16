def main():
    n = int(input())
    if n == 1:
        print(1)
        exit()

    now = 0
    for i in range(1, n):
        now += i

        if now >= n:
            print(i)
            exit()

if __name__ == '__main__':
    main()