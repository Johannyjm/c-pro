def main():
    n, p = map(int, input().split())
    mod = 1000000007
    print(((p-1) * pow(p-2, n-1, mod)) % mod)

if __name__ == '__main__':
    main()