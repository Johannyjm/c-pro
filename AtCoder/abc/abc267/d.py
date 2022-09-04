def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))

    dp = [[-(1<<60)] * m for _ in range(n)]
    dp[0][0] = a[0]

    for i in range(1, n):

        for j in range(i+1):
            k = i - j
            
            if k >= m: continue
            # print(i, j, k)

            if j == 0:
                dp[j][k] = max(dp[j][k], dp[j][k-1] + a[i] * (k+1))
            
            if k == 0:
                dp[j][k] = max(dp[j-1][k], a[i])

            if j != 0 and k != 0:
                dp[j][k] = max(dp[j][k], dp[j-1][k], dp[j-1][k-1] + a[i] * (k+1), dp[j][k-1] + a[i] * (k+1))
            
            
    # for i in range(n):
    #     print(*dp[i])
            
    
    res = -(1 << 60)
    for i in range(n):
        res = max(res, dp[i][m-1])
    print(res)




if __name__ == '__main__':
    main()