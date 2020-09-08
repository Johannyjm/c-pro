n = int(input())
s = input()
t = set([input() for _ in range(n)])

dp = {}
mod = 1000000007
def rec(idx):
    if(dp.get(idx) is not None): return dp[idx]

    ret = 0
    sub = s[: idx]
    if(sub in t): ret += 1
    
    for i in range(1, idx):
        sub1 = sub[i: ]
        if(sub1 not in t): continue

        ret = (ret + rec(i)) % mod
    
    dp[idx] = ret
    
    return ret

print(rec(len(s)))
