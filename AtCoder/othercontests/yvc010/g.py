def main():
    s = input()

    if s[0] != 'A':
        print('WA')
        exit()
    
    if s[2: -1].count('C') != 1:
        print('WA')
        exit()
    
    for c in s:
        if ord('A') <= ord(c) <= ord('Z'):
            if c not in ('A', 'C'):
                print('WA')
                exit()
    
    print('AC')

if __name__ == '__main__':
    main()