n = int(input())
a = list(map(int, input().split()))

sm = sum(a)
sm2 = sum(map(lambda x: x*x, a))

res = n*sm2 - sm**2
print(res)