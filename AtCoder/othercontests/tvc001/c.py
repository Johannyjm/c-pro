def main():
    a, b, c, d, e, f = map(int, input().split())
    c -= a
    d -= b
    e -= a
    f -= b

    print(abs(c*f - d*e) / 2)

if __name__ == '__main__':
    main()