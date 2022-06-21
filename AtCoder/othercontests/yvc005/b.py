def main():
    p = list(map(int, input().split()))

    for idx in p:
        print(chr(ord('a') + idx - 1), end='')
    print()

if __name__ == '__main__':
    main()