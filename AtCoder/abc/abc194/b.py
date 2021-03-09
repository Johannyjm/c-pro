n = int(input())
a = []
b = []
for _ in range(n):
    a_, b_ = map(int, input().split())
    a.append(a_)
    b.append(b_)

res = 1001001001
for i in range(n):
    for j in range(n):
        
        if i == j: sm = a[i] + b[j]
        else: sm = max(a[i], b[j])

        res = min(res, sm)

print(res)