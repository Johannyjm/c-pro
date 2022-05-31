from math import gcd

def main():
    n, a, b = map(int, input().split())
    res = (1 + n) * n // 2
    asum = (a + n//a * a) * (n//a) // 2
    bsum = (b + n//b * b) * (n//b) // 2

    lcm = a * b // gcd(a, b)
    csum = (lcm + n//lcm * lcm) * (n//lcm) // 2

    res -= asum + bsum
    res += csum

    print(res)

if __name__ == '__main__':
    main()