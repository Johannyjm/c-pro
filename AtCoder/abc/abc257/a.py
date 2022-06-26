def main():
    n, x = map(int, input().split())
    s = ''
    for i in range(26):
        s += chr(ord('A') + i) * n
    print(s)
    print(s[x-1])

if __name__ == '__main__':
    main()