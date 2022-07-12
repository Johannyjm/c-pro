def main():
    n = int(input())

    print((n + 1000 - 1) // 1000 * 1000 - n)

if __name__ == '__main__':
    main()