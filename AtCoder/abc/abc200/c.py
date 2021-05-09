n = int(input())
a = list(map(int, input().split()))
mxa = max(a)

mp = dict()
for e in a:
    if e in mp: mp[e] += 1
    else: mp[e] = 1

cnt = [[] for _ in range(200)]
for k in mp:
    cnt[k%200].append(mp[k])

res = 0
for k in mp:
    res += mp[k] * (mp[k]-1) // 2

for st in range(200):
    b = cnt[st]
    
    m = len(b)
    if m < 2: continue
    # print(st, b)
    now = b[-1]
    for i in range(m-2, -1, -1):
        res += b[i] * now
        now += b[i]

print(res)