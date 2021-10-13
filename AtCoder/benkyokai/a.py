import sys
sys.setrecursionlimit(10**6)
def main():
    n = int(input())
    a = list(map(int, input().split()))

    dp = [-1] * n
    def rec(i): # 足場i における最小コスト
    
        if dp[i] != -1: return dp[i]
        if i == 0: return 0

        ret = rec(i-1) + abs(a[i] - a[i-1])
        if i > 1: ret = min(ret, rec(i-2) + abs(a[i] - a[i-2]))

        dp[i] = ret

        return ret

    print(rec(n-1))

if __name__ == '__main__':
    main()