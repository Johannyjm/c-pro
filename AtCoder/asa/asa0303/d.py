n = int(input())
a = list(map(int, input().split()))

incs = []
cnt = 1
for i in range(n-1):
    if a[i] < a[i+1]:
        cnt += 1
    else:
        incs.append(cnt)
        cnt = 1
incs.append(cnt)
# print(incs)

res = n
for e in incs:
    res += e*(e-1)//2

print(res)
