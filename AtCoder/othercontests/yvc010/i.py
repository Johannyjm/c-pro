def nCk(n, k):
    ret = 1
    for m in range(1, n+1):
        ret *= m
    
    den1 = 1
    for m in range(1, k+1):
        den1 *= m
    
    den2 = 1
    for m in range(1, (n-k)+1):
        den2 *= m

    return ret // den1 // den2

def main():
    l = int(input())

    print(nCk(l-1, 11))

if __name__ == '__main__':
    main()