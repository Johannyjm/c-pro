def main():
    n, m, x, t, d = map(int, input().split())
    b = t - x*d

    if m >= x: print(t)
    else: print(b + m*d)

if __name__ == '__main__':
    main()