def main():
    n = int(input())
    
    interval = [0] * 220000
    for _ in range(n):
        l, r = map(int, input().split())

        # imos method
        interval[l] += 1
        interval[r] -= 1
    
    for i in range(210000):
        interval[i+1] += interval[i]
    
    for i in range(210000):
        if interval[i] != 0:
            interval[i] = True
        else:
            interval[i] = False
    
    # sprint(interval[: 51])
    
    res = []
    flg = False
    for i in range(220000):
        if not flg and interval[i]:
            flg = True
            fr = i
        
        if flg and not interval[i]:
            res.append((fr, i))
            flg = False
    
    for elem in res:
        print(*elem)

if __name__ == '__main__':
    main()