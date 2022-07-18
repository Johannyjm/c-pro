def main():
    n, m = map(int, input().split())
    s = input().split()
    t = set(input().split())

    for e in s:
        if e in t:
            print("Yes")
        else:
            print("No")

if __name__ == '__main__':
    main()