def main():
    n, k = map(int, input().split())
    a = list(map(lambda x:int(x)-1, input().split()))

    x = [0] * n
    y = [0] * n
    for i in range(n):
        x_, y_ = map(int, input().split())
        x[i] = x_
        y[i] = y_
    
    minsq = 1 << 60
    for i in a:

        maxsq = 0

        for j in range(n):
            print(i, j)

            maxsq = max(maxsq, (x[i]-x[j])**2 + (y[i]-y[j])**2)
        
        minsq = min(minsq, maxsq)
    
    print(minsq ** .5)


if __name__ == '__main__':
    main()