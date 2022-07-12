def main():
    s = input()
    n = len(s)

    for i in range(n):
        if i%2 == 0:
            if s[i] not in ('R', 'U', 'D'):
                print("No")
                exit()
        else:
            if s[i] not in ('L', 'U', 'D'):
                print("No")
                exit()
    
    print("Yes")

if __name__ == '__main__':
    main()