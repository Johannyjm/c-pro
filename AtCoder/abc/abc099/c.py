n = int(input())
INF = 1001001001
dp = [INF] * 110000

dp[1] = 1
base = 6
while(base < 110000):
    dp[base] = 1
    base *= 6
base = 9
while(base < 110000):
    dp[base] = 1
    base *= 9

for i in range(101000):
    
    dp[i+1] = min(dp[i+1], dp[i] + 1)

    base = 6
    while(i+base < 110000):
        dp[i+base] = min(dp[i+base], dp[i] + 1)
        base *= 6

    base = 9
    while(i+base < 110000):
        dp[i+base] = min(dp[i+base], dp[i] + 1)
        base *= 9

print(dp[n])
