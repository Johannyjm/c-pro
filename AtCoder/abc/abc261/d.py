from collections import defaultdict
def main():
    n, m  = map(int, input().split())
    x = [0] + list(map(int, input().split()))

    cy = defaultdict(int)
    for _ in range(m):
        c, y = map(int, input().split())
        cy[c] = y

    dp = [-1] * 5500 # dp[j] := i日目にj連続Hだった時に持っているコインの最大値

    # 1回目にH
    dp[1] = x[1] + cy[1]
    # 1回目にT
    dp[0] = 0

    for i in range(1, n): # 配るDP: i回目からi+1回目への遷移を考える
        nxt = [-1] * 5500

        for j in range(n):
            # i, j := i回目にj連続Hが出ている
            if dp[j] == -1: continue
            
            # i+1回目はH
            nxt[j+1] = max(nxt[j+1], dp[j] + x[i+1] + cy[j+1])

            # i+1回目はT
            nxt[0] = max(nxt[0], dp[j])
        

        dp = nxt
    
    print(max(dp))


if __name__ == '__main__':
    main()