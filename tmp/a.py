n = int(input())

dp = [[0] * 2 for _ in range(n+1)] # dp[day][b: 0, t: 1]

dp[0][0] = 1
print(dp)
for i in range(n):
    dp[i+1][0] += dp[i][0] + dp[i][1] * 2
    dp[i+1][1] += dp[i][0]

print(dp)
print(dp[n][0])

