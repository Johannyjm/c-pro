def main():
    h, n = map(int, input().split())
    a = [0] * n
    b = [0] * n
    for i in range(n):
        a_, b_ = map(int, input().split())
        a[i] = a_
        b[i] = b_
    
    INF = 1 << 60
    dp = [INF] * 22000
    dp[0] = 0

    for i in range(22000):
        if i-a[0] >= 0 and dp[i-a[0]] != INF:
            dp[i] = dp[i-a[0]] + b[0]
    
    for i in range(1, n):
        for j in range(22000):
            # print(i, j)
            if j-a[i] >= 0 and dp[j-a[i]] != INF:
                dp[j] = min(dp[j], dp[j-a[i]] + b[i])
    
    res = INF
    for i in range(h, 22000):
        res = min(res, dp[i])
    
    print(res)



if __name__ == '__main__':
    main()