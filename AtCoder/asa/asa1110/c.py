n = int(input())
a = [int(input()) for _ in range(n)]

res = 0
cnt = {}
for e in a:
    if(e in cnt): res += 1
    else: cnt[e] = 1

print(res)