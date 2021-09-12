def main():
    n = int(input())
    a = sorted(list(map(int, input().split())))
    res = 1

    for e in a:
        res *= e

        if res > 10**18:
            print(-1)
            exit()
    
    print(res)

if __name__ == '__main__':
    main()