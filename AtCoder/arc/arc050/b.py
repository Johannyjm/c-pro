def main():

    def check(k):
        R = r-k
        B = b-k

        if R < 0 or B < 0: return False

        count = R // (x-1) + B // (y-1)

        return count >= k


    r, b = map(int, input().split())
    x, y = map(int, input().split())

    ok = 0
    ng = 10**30

    while ng - ok > 1:

        mid = (ok + ng) // 2

        if check(mid):
            ok = mid
        else:
            ng = mid


    print(ok)

if __name__ == '__main__':
    main()