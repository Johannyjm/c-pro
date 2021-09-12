def main():
    n, a, b = map(int, input().split())

    whole = n // (a+b)
    rest = n % (a+b)

    print(a * whole + min(a, rest))

if __name__ == '__main__':
    main()