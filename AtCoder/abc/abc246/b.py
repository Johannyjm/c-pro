a, b = map(int, input().split())

l = (a**2 + b**2) ** 0.5
ratio = 1 / l
print(ratio * a, ratio * b)
