n, m = map(int, input().split())
a = list(map(int, input().split()))

sm = sum(a)
cnt = 0
for e in a:
    if(e >= sm/4): cnt += 1

if(cnt >= m): print("Yes")
else: print("No")