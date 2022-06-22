def main():
    n = int(input())

    val = n * 108 // 100
    price = 206

    if val < price:
        print('Yay!')
    elif val == price:
        print('so-so')
    else:
        print(':(')

if __name__ == '__main__':
    main()