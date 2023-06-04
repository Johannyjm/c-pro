def main():
    s = input()

    res = 0
    for num in range(10000):
        one = num // 1000
        two = num % 1000 // 100
        three = num % 100 // 10
        four = num % 10

        passwd = (one, two, three, four)

        valid = True
        for d in range(10):
            if s[d] == 'o':
                if d not in passwd:
                    valid = False
            if s[d] == 'x':
                if d in passwd:
                    valid = False
        
        if valid:
            res += 1
    
    print(res)


if __name__ == '__main__':
    main()