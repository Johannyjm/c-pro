n, m = map(int, input().split())
s = input()
INF = 1<<60
dp = [INF] * (n+1)
dp[0] = 0
now = 0

while True:
    changed = False
    for i in reversed(range(1, m+1)):
        ni = now + i
        if ni > n: continue
        if s[ni] == '1': continue
        
        dp[ni] = dp[now] + 1
        now = ni
        changed = True
        break

    if now == n: break
    if not changed:
        print(-1)
        exit()

# print(dp[n])
# print(dp)

res = []
prev = 0
cnt = 1
for i in range(n+1):
    if dp[i] != cnt: continue
    res.append(i - prev)
    prev = i
    cnt += 1

print(*res)
