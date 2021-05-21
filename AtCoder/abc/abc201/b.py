n = int(input())
print(sorted([input().split() for _ in range(n)], key=lambda x: int(x[1]))[-2][0])
