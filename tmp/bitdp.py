import sys
sys.setrecursionlimit(10**6)
n = int(input())
cost = [list(map(int, input().split())) for _ in range(n)]

dp = [[-1] * (1<<n) for _ in range(n)]

def rec(s, v):
    if dp[s][v] != -1: return dp[s][v]
    if s==(1<<n)-1 and v==0: return 1

    ret = 1<<60
    for nv in range(n):
        if nv:


print(rec(0, 0))
