def main():
    h = int(input())

    now = h
    count = 1
    res = 0
    while now > 0:

        res += count
        now //= 2
        count *= 2
    
    print(res)


if __name__ == '__main__':
    main()