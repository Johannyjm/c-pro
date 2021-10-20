def main():
    n, w = map(int, input().split())
    wv = [list(map(int, input().split())) for _ in range(n)]

    dp = [[0] * (w+1) for _ in range(n)]

    for j in range(wv[0][0], w+1):
        dp[0][j] = wv[0][1]
    
    for i in range(1, n):
        for j in range(w+1):
            dp[i][j] = max(
                dp[i-1][j], 
                dp[i][j-1]
            )

            if j-wv[i][0] >= 0:
                dp[i][j] = max(
                    dp[i][j], 
                    dp[i-1][j-wv[i][0]] + wv[i][1]
                )
    
    # for i in range(n):
    #     print(*dp[i])
    print(dp[n-1][w])


if __name__ == '__main__':
    main()