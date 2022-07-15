def main():
    s = input()
    n = len(s)

    res = 0
    for i in range(1<<n):
        right = [False] * n # l: F, r: T

        for j in range(n):
            if i & (1<<j):
                right[j] = True
        
        r = ''
        l = ''
        for j in range(n):
            if right[j]:
                r += s[j]
            else:
                l += s[j]
        
        if len(r) * len(l) == 0: continue

        r = list(r)
        l = list(l)
        
        r.sort(reverse=True)
        l.sort(reverse=True)
        
        r = ''.join(r)
        l = ''.join(l)

        r = int(r)
        l = int(l)

        res = max(res, r*l)
    
    print(res)



if __name__ == '__main__':
    main()