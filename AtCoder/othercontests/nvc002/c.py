def main():
    n = int(input())

    x = [0] * n
    y = [0] * n
    for i in range(n):
        a, b = map(int, input().split())
        x[i] = a
        y[i] = b
    
    res = 0
    for i in range(n):
        for j in range(i+1, n):

            dist2 = (x[i] - x[j]) ** 2 + (y[i] - y[j]) ** 2
            res = max(res, dist2)
    
    print(res ** .5)

if __name__ == '__main__':
    main()