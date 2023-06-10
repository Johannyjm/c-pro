from bisect import bisect_left, bisect_right

def main():
    n = int(input())
    a = list(map(int, input().split()))
    q = int(input())

    s = [0] * n
    for i in range(1, n):
        if i % 2 == 0:
            s[i] = s[i-1] + (a[i] - a[i-1])
        else:
            s[i] = s[i-1]
    
    # print(s)

    for _ in range(q):
        l, r = map(int, input().split())

        res = 0

        li = bisect_left(a, l)
        # print(f"{li=}")
        if li % 2 == 0:
            res += a[li] - l
        
        ri = bisect_right(a, r)
        # print(f"{ri=}")
        if ri % 2 == 0:
            res += r - a[ri-1]

        res += s[ri-1] - s[li]
        print(res)



if __name__ == '__main__':
    main()