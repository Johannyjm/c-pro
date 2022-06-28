def main():
    n, k, q = map(int, input().split())
    a = list(map(int, input().split()))
    ls = list(map(int, input().split()))

    for l in ls:

        if a[l-1] == n: continue

        if l==k:
            a[l-1]

if __name__ == '__main__':
    main()