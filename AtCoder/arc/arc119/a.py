n = int(input())

def calc(a, b):
    return a * (2 ** b)

a = 1
b = 0
while calc(a, b) < n: b += 1
while calc(a, b) < n: a += 1
print(a, b, calc(a, b))
print(a+b+(n-calc(a, b)))