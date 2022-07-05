def main():
    n, x = map(int, input().split())
    a = [0] * n
    b = [0] * n
    for i in range(n):
        a_, b_ = map(int, input().split())
        a[i] = a_
        b[i] = b_

    dp = [False] * 11000
    dp[0] = True
    

    for i in range(n):
        nxt = [False] * 11000

        for j in range(11000):
            if dp[j]:
                nxt[j] = True
                if j+a[i] < x: nxt[j+a[i]] = True
                if j+b[i] < x: nxt[j+b[i]] = True
        
        dp = nxt
    
    if dp[x]: print("Yes")
    else: print("No")

if __name__ == '__main__':
    main()