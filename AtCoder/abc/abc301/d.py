def main():
    s = input()
    n = int(input())
    val = 0
    s = list(reversed(s))

    for i in range(len(s)):

        if s[i] == "1":
            val += 2**i
    
    if val > n:
        print(-1)
        exit()

    s = list(reversed(s))
    for i in reversed(range(len(s))):

        if s[len(s)-i-1] != "?": continue

        if val + 2**i <= n:
            val += 2**i
    
    print(val)


if __name__ == '__main__':
    main()