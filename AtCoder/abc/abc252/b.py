def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    mx = max(a)

    for idx in b:
        idx -= 1

        if a[idx] == mx:
            print("Yes")
            exit()
    print("No")

if __name__ == '__main__':
    main()