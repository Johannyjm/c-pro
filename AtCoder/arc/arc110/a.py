from math import gcd
n = int(input())

p = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
mul = [0, 2]
res = [0, 3]
m = 2
for i in range(3, 31):
    g = gcd(m, i)
    if(g == 1):
        m *= i
    else:
        m *= i//g
    mul.append(m)
    res.append(m+1)

# print(mul)
print(res[n-1])

# for n in range(2, 31):

#     for i in range(2, n):
#         if(res[n-1]%i!=1):
#             print(n, i, res[n-1])