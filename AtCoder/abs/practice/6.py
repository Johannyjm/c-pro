def main():
    n, a, b = map(int, input().split())

    res = 0
    for num in range(1, n+1):
        d_sum = 0
        for d in str(num):
            d_sum += int(d)
        
        if a <= d_sum <= b:
            res += num
    
    print(res)

if __name__ == '__main__':
    main()