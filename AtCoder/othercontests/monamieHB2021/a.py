n = int(input())
n %= 26
n //= 2

res = [0, 3, 3, 4, 1, 1, 4, 4, 2, 2, 2, 5, 3]

print(res[n])