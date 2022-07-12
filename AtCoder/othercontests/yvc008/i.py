def main():
    a, b = map(int, input().split())

    res = [['.'] * 100 for _ in range(100)]
    now = 0
    flg = False
    for st in range(1, 100, 3):

        i = 0
        for j in range(st, 0, -1):
            res[i][j] = '#'
            now += 1

            if now == b:
                flg = True
                break

            i += 1
        
        if flg:
            break
    
    now = 0
    flg = False
    for st in range(2, 100, 3):
        i = 0
        for j in range(st, 0, -1):
            res[i][j] = "#"
            now += 1

            if now == a:
                flg = True
                break

            i += 1
        
        if flg:
            break
    
    print(100, 100)
    for i in range(100):
        for j in range(100): print(res[i][j], end='')
        print()

if __name__ == '__main__':
    main()