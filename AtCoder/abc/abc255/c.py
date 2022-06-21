def main():
    x, a, d, n = map(int, input().split())

    begin = a
    end = a + (n-1) * d

    if end < begin:
        begin, end = end, begin

    if x <= begin:
        print(begin - x)
        exit()

    if end <= x:
        print(x - end)
        exit()

    x -= begin

    x %= d

    print(min(x, d-x))
    


if __name__ == '__main__':
    main()
