def main():
    m, d = map(int, input().split())

    res = 0
    for i in range(1, m+1):
        for j in range(10, d+1):
            a, b = int(str(j)[0]), int(str(j)[1])

            if a>=2 and b>=2 and i == a*b: 
                # print(i, a, b)
                res += 1
    
    print(res)


if __name__ == '__main__':
    main()