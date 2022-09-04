from itertools import accumulate


def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    s = list(accumulate(a, initial=0))

    res = 0
    for i in range(m):
        res += a[i] * (i+1)
    
    now = res
    for i in range(n - m):
        now -= a[i] * 1
        now += a[i+m] * m
        now -= s[i+m] - s[i+1]

        # print(i, res, now)
        res = max(res, now)
    
    print(res)


if __name__ == '__main__':
    main()