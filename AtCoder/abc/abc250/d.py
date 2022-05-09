def is_prime(n):
    if(n == 1): return False

    for i in range(2, n):
        if i*i > n: break

        if(n % i == 0): return False
    
    return True

def main():

    primes = []
    for i in range(1, 1000000):
        if(is_prime(i)):
            primes.append(i)
    
    n = int(input())

    res = 0
    for i in range(len(primes)-1):
        if primes[i] * primes[i+1]*primes[i+1]*primes[i+1] > n: break

        p = primes[i]

        ok = i
        ng = len(primes)

        while ng - ok > 1:
            mid = (ok + ng) // 2

            q = primes[mid]

            if p*q*q*q <= n: ok = mid
            else: ng = mid
        
        res += ok - i

    print(res)

if __name__ == '__main__':
    main()