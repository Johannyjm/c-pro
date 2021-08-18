def main():

    def check(x):
        cnt = 0

        for i in range(n):
            if a[i] * f[i] <= x: continue

            cnt += a[i] - (x//f[i])

        return cnt <= k
    
    n = int(input())
    hs = [list(map(int, input().split())) for _ in range(n)]

    
    ok = 1 << 60
    ng = -1

    while ok - ng > 1:
        mid = (ok + ng) // 2

        if check(mid):
            ok = mid
        else:
            ng = mid

    print(ok)





if __name__ == "__main__":
    main()
