n, k = map(int, input().split())
a = list(map(int, input().split()))

res = []
for i in range(k, n):
    res.append(a[i-k] < a[i])

#print(res)
for b in res:
    if(b): print("Yes")
    else: print("No")