def main():
    n = int(input())

    h = 21 + n//60
    m = n%60

    if m < 10:
        m = '0' + str(m)
    
    print(str(h) + ':' + str(m))

if __name__ == '__main__':
    main()