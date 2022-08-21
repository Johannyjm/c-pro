def main():
    n, m, t = map(int, input().split())
    a = list(map(int, input().split()))
    x = [0] * m
    y = [0] * m
    for i in range(m):
        x_, y_ = map(int, input().split())
        x[i] = x_ - 1
        y[i] = y_
    
    bonus = [0] * n
    for i in range(m):
        bonus[x[i]] = y[i]

    ptr = 0 # 今の場所

    while True:
        need = a[ptr]
        t -= need

        if t <= 0:
            print("No")
            exit()
        
        ptr += 1

        t += bonus[ptr]

        if ptr == n-1:
            print("Yes")
            exit()


if __name__ == '__main__':
    main()