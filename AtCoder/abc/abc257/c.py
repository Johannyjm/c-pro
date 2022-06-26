def main():
    n = int(input())
    s = input()
    a = list(map(int, input().split()))

    count = {}
    for i in range(n):
        if a[i] in count:
            if s[i]=='0': count[a[i]][0] += 1
            else: count[a[i]][1] += 1
        else:
            if s[i]=='0': count[a[i]] = [1, 0]
            else: count[a[i]] = [0, 1]

    res = 0
    for c in s:
        if c == '1': res += 1

    ptr = 0
    prev = min(count.keys())
    now = res
    for k in sorted(count.keys()):
        if ptr == 0:
            ptr += 1
            continue

        now += count[prev][0]
        now -= count[prev][1]

        res = max(res, now)
        
        prev = k

    now = 0
    for c in s:
        if c == '0': now += 1
    
    res = max(res, now)

    print(res)        
        

if __name__ == '__main__':
    main()