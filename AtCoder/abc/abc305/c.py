def main():
    h, w = map(int, input().split())
    s = [input() for _ in range(h)]

    for i in range(h-1):
        for j in range(w-1):

            if s[i][j] == '.' and s[i][j+1] == '#' and s[i+1][j] == '#' and s[i+1][j+1] == '#':
                print(i+1, j+1)
                exit()
            if s[i][j] == '#' and s[i][j+1] == '.' and s[i+1][j] == '#' and s[i+1][j+1] == '#':
                print(i+1, j+2)
                exit()
            if s[i][j] == '#' and s[i][j+1] == '#' and s[i+1][j] == '.' and s[i+1][j+1] == '#':
                print(i+2, j+1)
                exit()
            if s[i][j] == '#' and s[i][j+1] == '#' and s[i+1][j] == '#' and s[i+1][j+1] == '.':
                print(i+2, j+2)
                exit()
             

if __name__ == '__main__':
    main()