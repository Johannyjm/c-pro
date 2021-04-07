def p(i, j):
    return 1 / (1 + pow(10, (j - i) / 400))

k = int(input())
R = list()
for _ in range(1<<k):
    R_ = int(input())
    R.append(R_)

dp = [[0.0] * (1<<k) for _ in range(k)]

for i in range(k):
    for j in range(1<<k):
        
        if i == 0:
            if j%2 == 0: dp[i][j] = p(R[j], R[j+1])
            else: dp[i][j] = p(R[j], R[j-1])
            continue

        if j%(1<<(i+1)) < 1<<i:
            l = j//(1<<i) * (1<<i) + (1<<i)
            r = l + (1<<i)

        else:
            l = j//(1<<i) * (1<<i) - (1<<i)
            r = l + (1<<i)

        for ii in range(l, r):
            dp[i][j] += dp[i-1][j] * (dp[i-1][ii] * p(R[j], R[ii]))

for res in dp[k-1]:
    print(res)


