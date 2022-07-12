def main():
    n = int(input())

    res = 1
    for i in range(1, n+1):
        res *= i
        res %= 1000000007
    
    print(res)

if __name__ == '__main__':
    main()