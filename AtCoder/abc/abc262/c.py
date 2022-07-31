def main():
    n = int(input())
    a = list(map(int, input().split()))

    same = 0
    for i in range(n):
        if a[i] == i+1:
            same += 1
    
    res = 0
    for i in range(n):
        
        if a[i] == i+1:
            res += same - 1
            same -= 1
            continue

        if a[i] > i+1:
            if a[a[i]-1] == i+1:
                res += 1

    print(res)


if __name__ == '__main__':
    main()