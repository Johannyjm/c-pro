def main():
    n, c, k = map(int, input().split())
    ts = [int(input()) for _ in range(n)]
    ts.sort()

    res = 0
    now = ts[0]
    count = 1
    for i in range(1, n):
        t = ts[i]

        if now == -1:
            now = t
            count = 1
            continue

        if t <= now + k:
            count += 1
            
            if count == c:
                count = 1
                now = -1
                res += 1
        
        else:
            count = 1
            now = t
            res += 1

    if count > 0: res += 1

    print(res)
            

if __name__ == '__main__':
    main()