def main():
    n = int(input())
    a = list(map(int, input().split()))

    res = []
    res.append(a[0])
    for i in range(1, n):
        if abs(a[i] - a[i-1]) == 1:
            res.append(a[i])
            continue
        
        if a[i] > a[i-1]:
            for elem in range(a[i-1]+1, a[i]+1):
                res.append(elem)
        
        if a[i] < a[i-1]:
            for elem in range(a[i-1]-1, a[i]-1, -1):
                res.append(elem)
    
    print(*res)


if __name__ == '__main__':
    main()