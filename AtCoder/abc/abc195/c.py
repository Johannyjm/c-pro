n = int(input())

res = 0

for i in range(5):
    base = pow(10, (i+1)*3)
    tmp = n % base
    if n // base != 0:
        if n // (base*1000) != 0: res += 1000 * (i + 1)
        else: res += (tmp + 1) * (i + 1)
    print(base, tmp, res)

print(res)

