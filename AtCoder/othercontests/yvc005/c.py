def main():
    a, b, c, d = map(int, input().split())

    if not (b<c or d<a):
        print("Yes")
    else:
        print("No")

if __name__ == '__main__':
    main()