from itertools import accumulate

def main():
    n, p, q, r = map(int, input().split())
    a = list(map(int, input().split()))

    s = list(accumulate(a, initial=0))
    print(s)

    x, y, z, w = -1, -1, -1, -1

    l = 0
    while l < n:

        r = l+1

        while s[r] - s[l] < p+q+r:
            r += 1
        
        if s[r] - s[l] == p+q+r:
            x = r
            w = l
            break

        else:
            l += 1

if __name__ == '__main__':
    main()