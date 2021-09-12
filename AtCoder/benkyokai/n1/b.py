def main():
    n = int(input())
    w = list(map(int, input().split()))

    res = 1001001001
    for i in range(n):
        w1 = sum(w[: i])
        w2 = sum(w[i: ])

        res = min(res, abs(w1 - w2))

    print(res)

if __name__ == '__main__':
    main()