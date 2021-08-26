def main():
    n = int(input())

    res = 0
    for i in range(1, 10 ** 7):
        num = str(i) * 2
        if int(num) <= n:
            res += 1
        else:
            break
    
    print(res)



if __name__ == '__main__':
    main()