a, b, k = map(int, input().split())
n = a+b

res = ''

while True:
    froma = [0] * (n+1)
    fromb = [0] * (n+1)

    dp = [[-1] * 31 for _ in range(31)]
    def rec(x, y):
        # print(x, y)
        if dp[x][y] != -1:
            return dp[x][y]
        if x==0 or y==0:
            dp[x][y] = 1
            return 1

        A = rec(x-1, y)
        B = rec(x, y-1)
        # assert froma[n-x-y] == A
        # assert fromb[n-x-y] == B
        
        # if x+y == n:
        #     froma = A
        #     fromb = B
        froma[n-x-y] += A
        fromb[n-x-y] += B

        ret = A+B
        dp[x][y] = ret

        return ret

    # print(rec(a, b))
    # print(dp)
    # print(a, b, res)
    _ = rec(a, b)
    # print(rec(a, b))
    # print(a, b)
    # print(froma)
    # print(fromb)

    if b>=0 and k > froma[0]:
        k -= froma[0]
        res += 'b'
        b -= 1
    elif a>=0 and k <= froma[0]:
        res += 'a'
        a -= 1
    n = a+b
    print(a, b, k, froma[0], fromb[0])
    if k == 1:
        if a==b: res += 'a'*a + 'b'*b
        elif a>b: res += 'a' * a
        else: res += 'b' * b
        break
    if a+b == 0: break
print(res)
