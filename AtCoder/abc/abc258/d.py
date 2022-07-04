def main():
    n, x = map(int, input().split())
    a = [0] * n
    b = [0] * n
    for i in range(n):
        a_, b_ = map(int, input().split())
        a[i] = a_
        b[i] = b_
    
    res = 10 ** 20
    cumsum = 0
    for i in range(n):
        if i+1 > x:
            break
        
        cumsum += a[i] + b[i]

        cand = cumsum + b[i] * (x - i - 1)

        res = min(res, cand)
    
    print(res)

if __name__ == '__main__':
    main()