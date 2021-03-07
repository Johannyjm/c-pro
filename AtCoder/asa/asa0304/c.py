n = int(input())
a = list(map(lambda x: int(x)-1, input().split()))

res = 0
for i in range(n):
    if a[a[i]] == i: res += 1

print(res//2)