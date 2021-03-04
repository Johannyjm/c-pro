n = int(input())
b = list(map(int, input().split()))

res = b[0] + b[-1]
for i in range(n-2):
    res += min(b[i], b[i+1])

print(res)