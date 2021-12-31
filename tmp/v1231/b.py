n = int(input())
if n >= 42: n += 1

if n < 10:
    res = 'AGC00' + str(n)
else:
    res = 'AGC0' + str(n)

print(res)
