def main():
    
    n = int(input())
    a = list(map(int, input().split()))

    res = 0
    for e in a:

        while e % 2 == 0:
            e //= 2
            res += 1
    
    print(res)

if __name__ == '__main__':
    main()