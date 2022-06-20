def main():
    n, k = map(int, input().split())

    res = 0
    for i in range(k, n+2):
        l = (i-1) * i // 2
        r = (n-i+1 + n) * i // 2

        # print(i, l, r)
        res += r - l + 1
        res %= 1000000007
    
    print(res)

if __name__ == '__main__':
    main()