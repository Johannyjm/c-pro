def main():
    n = int(input())
    a = list(map(int, input().split()))

    res = 1
    now = a[0]

    for i in range(1, n):
        if a[i] >= now:
            res += 1
            now = a[i]
    
    print(res)


if __name__ == '__main__':
    main()