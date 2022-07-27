def main():
    a, b, c, d = map(int, input().split())

    if b < c or d < a:
        print(0)
    
    elif a <= c <= d <= b:
        print(d-c)
    elif c <= a <= b <= d:
        print(b-a)
    elif a <= c <= b or c <= b <= d:
        print(b-c)
    elif c <= a <= d or a <= d <= b:
        print(d-a)


if __name__ == '__main__':
    main()