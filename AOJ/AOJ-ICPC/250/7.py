while(True):
    w, h = map(int, input().split())
    if(w == 0): break

    s = [input() for _ in range(h)]
    dp = [[0] * w for _ in range(h)]

    res = 0
    for i in range(h): 
        for j in range(w):
            if(s[i][j].isalpha()): continue

            sm = 0
            if(i > 0): sm = dp[i-1][j] * 10
            if(j > 0): sm = max(sm, dp[i][j-1] * 10)

            dp[i][j] = sm + int(s[i][j])
            
            res = max(res, dp[i][j])
        
    print(res)
