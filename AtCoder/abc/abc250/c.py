def main():
    n, q = map(int, input().split())

    a = list(range(1, n+1))
    inds = dict()
    for i in range(n):
        inds[i+1] = i

    for _ in range(q):
        x = int(input())

        if inds[x] == n-1:
            a[n-1], a[n-2] = a[n-2], a[n-1]

            tmp = inds[a[n-1]]
            inds[a[n-1]] = inds[a[n-2]]
            inds[a[n-2]] = tmp
            
        else:
            a[inds[x]], a[inds[x]+1] = a[inds[x]+1], a[inds[x]]

            tmp = inds[a[inds[x]]]
            inds[a[inds[x]]] = inds[a[inds[x]+1]]
            inds[a[inds[x]+1]] = tmp

        print()
        print(*a)

    print(*a)


if __name__ == '__main__':
    main()