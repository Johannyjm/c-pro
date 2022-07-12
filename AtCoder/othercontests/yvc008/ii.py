def main():
    a, b = map(int, input().split())
    gt = ''
    le = ''

    if a >= b:
        gt = '.'
        le = '#'
    else:
        gt = '#'
        le = '.'
    
    

if __name__ == '__main__':
    main()