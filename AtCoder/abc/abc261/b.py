def main():
    n = int(input())
    a = [input() for _ in range(n)]

    valid = True
    for i in range(n):
        for j in range(n):
            if i==j and a[i][j]!='-':
                valid = False

            if i!=j and a[i][j]=='-':
                valid = False
            
            if a[i][j]=='D' and a[j][i]!='D':
                valid = False
            
            if a[i][j]=='W' and a[j][i]!='L':
                valid = False

            if a[i][j]=='L' and a[j][i]!='W':
                valid = False
    
    if valid: print('correct')
    else: print('incorrect')


if __name__ == '__main__':
    main()