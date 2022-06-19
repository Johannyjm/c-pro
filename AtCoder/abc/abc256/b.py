def main():
    n = int(input())
    a = list(map(int, input().split()))

    field = [0] * 4
    res = 0

    for gain in a:

        field[0] = 1

        for i in reversed(range(4)):

            if field[i] == 0: continue

            if i+gain >= 4:
                field[i] = 0
                res += 1
            
            else:
                field[i] = 0
                field[i+gain] = 1
  
    print(res)

if __name__ == '__main__':
    main()