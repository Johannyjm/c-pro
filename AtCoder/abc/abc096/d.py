primes = []

def isprime(n):
    for i in range(2, n):
        if(i*i > n): break
        if(n%i == 0): return False
    
    return True

for i in range(2, 55556):
    if(isprime(i)):
        if(i%5==1): primes.append(i)
    
    if(len(primes) > 55): break

print(len(primes))
import random


for i in range(100):
    a = random.sample(primes, 5)
    print()
    print(a)
    if(isprime(sum(a))): print('prime', sum(a))
    else: print('not prime', sum(a))