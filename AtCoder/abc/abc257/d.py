def main():
    n, x = map(int, input().split())

    # a + b + c = x s.t. 1 <= a, b, c <= n
    # a,bを決めた時，c:= x-a-b が　1<=c<=n

    result = 0
    for a in range(1, n+1): # a < b < c
        for b in range(a+1, n+1):

            c = x - a - b

            if not a < b < c:
                continue

            if 1 <= c <= n :
                result += 1


    

    print(result)

if __name__ == '__main__':
    main()