n = int(input())
h = list(map(int, input().split()))

import sys
sys.setrecursionlimit(10**6)

INF = 10**12

memo = [-1] * n

def rec(i): # return min cost in i idx
    if(i == 0): return 0
    if(memo[i] != -1): return memo[i]

    ret = rec(i-1) + abs(h[i]-h[i-1])
    if(i > 1): ret = min(ret, rec(i-2) + abs(h[i] - h[i-2]))

    memo[i] = ret
    return ret

print(rec(n-1))

