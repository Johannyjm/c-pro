def main():
    l, r = map(int, input().split())
    l -= 1
    r -= 1

    s = input()
    res = s[: l] + s[l: r+1][:: -1] + s[r+1: ]
    print(res)

if __name__ == '__main__':
    main()