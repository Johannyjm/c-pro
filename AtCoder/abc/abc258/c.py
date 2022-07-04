def main():
    n, q = map(int, input().split())
    s = input()

    now = 0 # 0 ~ n-1
    for _ in range(q):
        t, x = map(int, input().split())

        if t == 1:
            # query 1

            now += n*10
            now -= x
            now %= n
        
        if t == 2:
            # query 2

            idx = now + x-1
            idx %= n

            print(s[idx])

if __name__ == '__main__':
    main()