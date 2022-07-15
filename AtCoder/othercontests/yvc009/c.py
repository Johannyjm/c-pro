def main():
    n, k = map(int, input().split())
    ab = [list(map(int, input().split())) for _ in range(n)]

    ab.sort()

    now = k
    prev = 0
    for i in range(n):
        a, b, = ab[i]

        cost = a - prev
        if now < cost:
            print(prev + now)
            exit()
        
        else:
            now -= cost
            now += b
            prev = a

    print(prev + now)

if __name__ == '__main__':
    main()