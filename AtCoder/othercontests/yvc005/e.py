def main():
    n = int(input())

    res = 0

    if 1000 <= n <= 999999:
        res = n+1 - 1000
    
    if 1000000 <= n <= 999999999:
        res = 1000000 - 1000
        res += 2*(n-1000000+1)
    
    if 1000000000 <= n <= 999999999999:
        res = 1000000 - 1000
        res += 2*(1000000000-1000000)

        res += 3*(n-1000000000+1)
    
    if 1000000000000 <= n:
        res = 1000000 - 1000
        res += 2*(1000000000-1000000)
        res += 3*(1000000000000 - 1000000000)

        res += 4*(n-1000000000000+1)

    if n == 1000000000000000:
        res += 1
    
    print(res)


if __name__ == '__main__':
    main()