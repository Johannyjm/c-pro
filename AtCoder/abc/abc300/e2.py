MOD = 998244353

def mul_mod(a, b):
    return (a * b) % MOD

def pow_mod(x, n):
    if n == 0:
        return 1
    elif n % 2 == 0:
        return pow_mod(mul_mod(x, x), n // 2)
    else:
        return mul_mod(x, pow_mod(x, n - 1))

def inv_mod(x):
    return pow_mod(x, MOD - 2)

def solve(n):
    f = [0] * (n + 1)
    f[1] = 1
    for i in range(2, n + 1):
        for j in range(1, 7):
            if j < i:
                f[i] += f[i - j]
        f[i] = mul_mod(f[i], inv_mod(6))
    return f[n]

n = int(input())
print(mul_mod(solve(n), inv_mod(7)))