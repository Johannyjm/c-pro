def main():
    n, m, x, t, d = map(int, input().split())

    b = t - x*d
    if m <= x:
        print(b + d*m)
    else:
        print(t)

if __name__ == '__main__':
    main()