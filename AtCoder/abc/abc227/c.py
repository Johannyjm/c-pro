def main():
    n = int(input())
    print(*range(1, n+1))
    for i in range(1, n+1):
        print(n//i, end=' ')
    print()

if __name__ == '__main__':
    main()