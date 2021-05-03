n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

cnt = 0
for i in range(n):
    cnt += abs(a[i] - b[i])

if cnt > k or (cnt <= k and (cnt-k)%2 == 1): print("No")
else: print("Yes")