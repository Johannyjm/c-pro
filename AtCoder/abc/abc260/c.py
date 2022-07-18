def main():
    n, x, y = map(int, input().split())

    dp = [[0]*2 for _ in range(n+1)] # 0: red, 1: blue
    dp[n][0] = 1 # one red

    for i in range(n, 1, -1):
        dp[i][1] += dp[i][0] * x
        dp[i-1][0] += dp[i][0] + dp[i][1]

        dp[i-1][1] += dp[i][1] * y
    
    print(dp[1][1])


if __name__ == '__main__':
    main()