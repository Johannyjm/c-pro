def main():
    
    n = int(input())
    a = [0] + list(map(int, input().split()))

    res = [0] * (n+1)

    for i in range(n, 0, -1):
        sm = 0
        for j in range(i, n+1, i):
            sm += res[j]
        
        if sm%2 != a[i]:
            res[i] = 1 - res[i]
    
    print(res.count(1))
    for i in range(1, n+1):
        if res[i] == 1:
            print(i, end=' ')
    print()

if __name__ == '__main__':
    main()