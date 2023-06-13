from math import comb

def main():
    a, b, k = map(int, input().split())
    n = a + b
    n_ = n
    res = ""

    for _ in range(n_):
        
        n = a + b

        if a*b == 0:
            res += 'a' * a + 'b' * b
            break

        comb_val = comb(n-1, a-1)
        if k <= comb_val:
            res += "a"
            a -= 1
        
        else:
            res += "b"
            b -= 1
            k -= comb_val
    
    print(res)

if __name__ == '__main__':
    main()