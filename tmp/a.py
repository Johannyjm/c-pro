from collections import defaultdict

def main():
    # n: 13, k: 3
    # [-2 3 4 1 2 2 4 8 3 7 4 10 1]
    # → 5
    # dp[element] := elementが等差数列の最後尾になるときの長さ
    # dp[element] = dp[element - k] + 1




    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    dp = defaultdict(int)
    for elem in a:

        dp[elem] = dp[elem - k] + 1
    
    res = max(dp.values())

    if res < 2:
        print(-1)
    else:
        print(res)    


if __name__ == '__main__':
    main()