n = int(input())
p = list(map(int, input().split()))
res = max(p[1: ]) + 1 - p[0]
print(max(0, res))
