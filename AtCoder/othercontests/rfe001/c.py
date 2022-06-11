def main():
    n = int(input())
    s = input()

    res = 'b'
    for i in range(1, 1000):

        if i%3 == 1:
            res = 'a' + res + 'c'
        
        if i%3 == 2:
            res = 'c' + res + 'a'
        
        if i%3 == 0:
            res = 'b' + res + 'b'

        if s == res:
            print(i)
            exit()
        
        if len(res) > n:
            print(-1)
            exit()

if __name__ == '__main__':
    main()