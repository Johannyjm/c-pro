def main():
    s = input()
    n = len(s)

    res = 0
    for i in range(1<<n):
        a = ''
        b = ''
        for j in range(n):
            if i & (1<<j):
                a += s[j]
            else:
                b += s[j]
        if len(a)==0 or len(b)==0: continue

        a = list(a)
        b = list(b)
        a.sort(reverse=True)
        b.sort(reverse=True)

        if a[0] == '0' or b[0] == '0': continue

        a = int(''.join(a))
        b = int(''.join(b))
         
        # print(a, b)

        res = max(res, a*b)
    print(res)

if __name__ == '__main__':
    main()