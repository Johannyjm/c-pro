def main():
    n = int(input())

    dp = [[0] * 10 for _ in range(n+1)]
    for i in range(1, 10):
        dp[1][i] = 1
    
    for i in range(2, n+1):

        for j in range(1, 10):
            if j > 1: dp[i][j] += dp[i-1][j-1]
            dp[i][j] += dp[i-1][j]
            if j < 9: dp[i][j] += dp[i-1][j+1]

            dp[i][j] %= 998244353
    
    res = 0
    for i in range(1, 10):
        res += dp[n][i]
        res %= 998244353
    
    print(res)

if __name__ == '__main__':
    main()