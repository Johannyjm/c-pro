def main():
    a, b, k = map(int, input().split())

    res = 0
    while True:
        if a >= b:
            print(res)
            exit()
        
        a *= k
        res += 1

if __name__ == '__main__':
    main()