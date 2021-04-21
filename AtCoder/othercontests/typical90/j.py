n = int(input())
c = [0] * n
p = [0] * n
for i in range(n):
    c_, p_ = map(int, input().split())
    if c_ == 1: c[i] = p_
    else: p[i] = p_

smc = [0] * (n+1)
smp = [0] * (n+1)

for i in range(n):
    smc[i+1] = smc[i] + c[i]
    smp[i+1] = smp[i] + p[i]

q = int(input())
for _ in range(q):
    l, r = map(int, input().split())
    print(smc[r] - smc[l-1], smp[r] - smp[l-1])