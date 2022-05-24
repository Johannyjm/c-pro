def main():
    n = int(input())
    a = list(map(int, input().split()))

    cnt = dict()
    for e in a:
        if e not in cnt:
            cnt[e] = 1
        else:
            cnt[e] += 1
    
    res = n * (n-1) * (n-2) // 6

    for k in cnt:
        if cnt[k] == 1: continue

        if cnt[k] == 2:
            res -= n-2

        if cnt[k] > 2:
            res -= cnt[k] * (cnt[k]-1) * (cnt[k]-2) // 6
            res -= cnt[k] * (cnt[k]-1) // 2 * (n-cnt[k])
    print(res)

if __name__ == '__main__':
    main()