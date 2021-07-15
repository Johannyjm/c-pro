n = int(input())
c = list(map(int, input().split()))

c.sort()

res = 1
for i, e in enumerate(c):
    res *= max(0, e-i)

print(res % 1000000007)