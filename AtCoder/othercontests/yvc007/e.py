def main():
    sx, sy, gx, gy = map(int, input().split())

    a = (-gy-sy)/(gx-sx)

    print(-(sy-a*sx)/a)

if __name__ == '__main__':
    main()