def main():
    n, k = map(int, input().split())
    r, s, p = map(int, input().split())
    t = input()

    hand = ''
    res = 0
    for i in range(n):

        if t[i] == 'r':
            if i <= k or hand[i-k] != 'p':
                res += p
                hand += 'p'
            else:
                hand += '*'
        if t[i] == 's':
            if i <= k or hand[i-k] != 'r':
                res += r
                hand += 'r'
            else:
                hand += '*'
        if t[i] == 'p':
            if i <= k or hand[i-k] != 's':
                res += s
                hand += 's'
            else:
                hand += '*'
    print(res)

if __name__ == '__main__':
    main()