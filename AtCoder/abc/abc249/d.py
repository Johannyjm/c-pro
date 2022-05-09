def main():
    n = int(input())
    a = list(map(int, input().split()))

    res = 0
    for i in range(n):
        for j in range(n):
            for k in range(n):

                if a[i] % a[j] == 0 and a[i] // a[j] == a[k]:
                    print(i, j, k)
                    print(a[i], a[j], a[k])
                    print()
                    res += 1
    
    print(res)

if __name__ == '__main__':
    main()