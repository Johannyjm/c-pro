x, y, a, b = map(int, input().split())

res = 0
while(min(x*a, x+b) < y and x*a < x+b):
    x *= a
    res += 1
# print(res, x)
print(res + (y-1-x)//b)