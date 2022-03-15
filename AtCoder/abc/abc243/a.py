def main():
    v, a, b, c = map(int, input().split())

    now = v

    while True:
        now -= a
        if now < 0:
            print('F')
            exit()
        now -= b
        if now < 0:
            print('M')
            exit()

        now -= c
        if now < 0:
            print('T')
            exit()

if __name__ == '__main__':
    main()