from math import gcd

def is_prime(n):
    if n==1: return False

    for i in range(2, n):
        if i*i > n: break
        if n % i == 0:
            return False

    return True

def main():
    n = int(input())
    x = list(map(int, input().split()))

    primes = list()
    for i in range(1, 51):
        if is_prime(i): primes.append(i)

    # print(primes)

    m = len(primes)
    res = float('inf')
    for i in range(1<<m):
        use = [0] * m
        for j in range(m):
            if i & (1<<j):
                use[j] = 1

        cand = 1
        for j in range(m):
            if use[j] == 0: continue
            cand *= primes[j]

        flg = True
        for j in range(n):
            if gcd(x[j], cand) == 1: flg = False

        if not flg: continue

        res = min(res, cand)

    print(res)


if __name__ == "__main__":
    main()
