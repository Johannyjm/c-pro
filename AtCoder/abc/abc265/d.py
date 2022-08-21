from itertools import accumulate

def binary_search(key, a):
    n = len(a)

    l = -1
    r = n
    while r-l > 1:
        m = (l+r) // 2

        if a[m] == key:
            return m
        
        if a[m] < key:
            l = m
        else:
            r = m
    
    return -1

def main():
    n, p, q, r = map(int, input().split())
    a = list(map(int, input().split()))

    s = list(accumulate(a, initial=0))
    print(s)

    x, y, z, w = -1, -1, -1, -1

    for l in range(n):
        
        key = p+q+r - s[l]
        
        idx = binary_search(key, s)

        if idx != -1:
            print(l, r, s[l], s[r], key)
            x, w = l, r
            break
    
    print(x, y, z, w)




    # l = 0
    # while l < n:

    #     r = l+1

    #     while s[r] - s[l] < p+q+r:
    #         r += 1
        
    #     if s[r] - s[l] == p+q+r:
    #         x = r
    #         w = l
    #         break

    #     else:
    #         l += 1

if __name__ == '__main__':
    main()