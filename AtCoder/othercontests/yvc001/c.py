from math import gcd

def f(m, a):
    n = len(a)
    ret = 0
    for i in range(n):
        ret += m % a[i]
    
    return ret

def main():

    n = int(input())
    a = list(map(int, input().split()))

    res = 0
    for e in a:
        res += e-1
    
    print(res)


if __name__ == '__main__':
    main()