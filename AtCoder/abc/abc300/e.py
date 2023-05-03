from collections import defaultdict

def main():
    n = int(input())

    # dp = [[n, 0.0]*7  for _ in range(100)]
    dp = [(n, 1.0)]
    # dp = defaultdict(int)
    # dp[n] = 1.0

    res = 0
    while len(dp) > 0:

        nxt = defaultdict(int)
        for val, pr in dp:

            for div in range(2, 7):

                if val % div == 0:
                    
                    nxt_val = val // div
                    nxt_pr = pr / 6
                    nxt[nxt_val] += nxt_pr

        nxt_dp = []        
        for key in nxt:

            if key == 1:
                res += nxt[key]
            
            else:
                nxt_dp.append((key, nxt[key]))
        
        dp = nxt_dp

    
    print(res)




if __name__ == '__main__':
    main()