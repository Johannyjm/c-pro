import math
a, b, k = map(int, input().split())

n = a+b
l = a+b
res = ''
for i in range(l):
    if a > 0:
        choose_a = math.factorial(n-1) // (math.factorial(a-1) * math.factorial(b))
    else:
        choose_a = 0

    if k <= choose_a:
        res += 'a'
        a -= 1
    else:
        res += 'b'
        b -= 1
        k -= choose_a

    n = a+b

print(res)