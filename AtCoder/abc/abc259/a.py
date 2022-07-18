def main():
    n, m, x, t, d = map(int, input().split())

    if m <= x:
        print(m * d)
    else:
        print(x * d)

if __name__ == '__main__':
    main()