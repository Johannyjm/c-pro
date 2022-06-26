def main():
    n, k, q = map(int, input().split())
    a = list(map(int, input().split()))
    ls = list(map(int, input().split()))

    for l in ls:
        l -= 1

        if a[l] == n: continue
        if l == k-1:
            a[l] += 1
        else:
            if a[l] + 1 == a[l+1]:
                pass
            else:
                a[l] += 1
    
    print(*a)

if __name__ == '__main__':
    main()