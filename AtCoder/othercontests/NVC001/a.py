def main():
    s = input()

    res = 0
    for k in range(10000):
        p = str(k).zfill(4)

        valid = True
        for i in range(10):
            if s[i] == 'o' and str(i) not in p:
                valid = False
            if s[i] == 'x' and str(i) in p:
                valid = False
        
        if valid:
            res += 1

    print(res)

if __name__ == '__main__':
    main()