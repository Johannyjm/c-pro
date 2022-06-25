def main():
    n, x = map(int, input().split())
    s = input()

    res = x
    for c in s:
        if c == 'o':
            res += 1
        else:
            res = max(0, res-1)
    
    print(res)

if __name__ == '__main__':
    main()