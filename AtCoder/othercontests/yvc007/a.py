def main():
    a, b = map(int, input().split())
    mx = 2*a + 100

    print(mx - b)

if __name__ == '__main__':
    main()