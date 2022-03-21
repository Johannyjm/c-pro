
def main():
    n = int(input())
    res = 0
    for i in range(1, n+1):
        if i * i > n: break

        res += n//i
        if i*i != n and i!=(n//i) : res += (n//i - n // (i+1)) * i
    
    print(res)

    res = 0
    for i in range(1, n+1):
        res += n//i
        print(i, n//i, end=', ')

    print(res)

if __name__ == '__main__':
    main()