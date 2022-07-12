def main():
    s = input()
    n = len(s)
    a, b, c, d = map(int, input().split())

    res = [''] * (n+4)
    res[a] = '"'
    res[b+1] = '"'
    res[c+2] = '"'
    res[d+3] = '"'

    ptr = 0
    s_l = list(reversed(s))
    while True:
        if res[ptr] != '"':
            res[ptr] = s_l.pop()
        
        ptr += 1
        if ptr == n+4:
            break
    
    print(''.join(res))

if __name__ == '__main__':
    main()