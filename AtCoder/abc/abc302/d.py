def main():
    n, m, d = map(int, input().split())

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    a.sort(reverse=True)
    b.sort(reverse=True)
    i = 0
    j = 0
    res = -1

    while i < n and j < m:
        if abs(a[i] - b[j]) <= d:
            res = max(res, a[i] + b[j])
            i += 1
            j += 1
        elif a[i] > b[j]:
            i += 1
        else:
            j += 1
    print(res)

if __name__ == '__main__':
    main()
