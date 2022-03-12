def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    res1 = 0
    for i in range(n):
        if a[i] == b[i]: res1 += 1

    sa = set(a)
    sb = set(b)


    res2 = 0
    for i in range(n):
        for j in range(n):
            if i >= j: continue
            if a[i] == b[j]: res2 += 1


    print(res1)
    print(res2)
if __name__ == '__main__':
    main()