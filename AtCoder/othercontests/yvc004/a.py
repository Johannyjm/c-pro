def main():
    s = input()
    n = len(s)
    rs = s[::-1]
    res = 0
    for i in range(n//2):
        if s[i] != rs[i]:
            res += 1
    
    for i in range(n//2):
        if s[i] != s[-i-1]: # s[0] <-> s[-1], s[1] <-> s[-2]
            res += 1
    
    print(res)

if __name__ == '__main__':
    main()