def main():
    h, w = map(int, input().split())
    s = [input() for _ in range(h)]

    res = 0
    for i in range(h-1):
        for j in range(w):
            if s[i][j] == '.' and s[i+1][j] == '.':
                res += 1
    
    for i in range(h):
        for j in range(w-1):
            if s[i][j] == '.' and s[i][j+1] == '.':
                res += 1
    
    print(res)

if __name__ == '__main__':
    main()