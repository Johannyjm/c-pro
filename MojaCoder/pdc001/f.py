def isprime(n):
    if n == 1: return False
    for i in range(2, n):
        if i*i > n: break
        if n%i == 0: return False
    return True

primes = []

for i in range(1, 1000000):
    if isprime(i): primes.append(i)

print(len(primes))
# print(primes[: 10])
a, b = map(int, input().split())

res = 0
for prime in primes:
    base = 1

    while True:
        num = prime ** base
        if a <= num <= b:
            res = max(res, base)
        base += 1
        if num > b:
            break

print(res)