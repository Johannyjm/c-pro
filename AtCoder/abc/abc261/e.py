
def main():
    n, c = map(int, input().split())
    fs = [0] * n

    for i in range(n):
        t, a = map(int, input().split())
        if i == 0:
            if t == 1:
                fs[i] = lambda x: x&a
            if t == 2:
                fs[i] = lambda x: x|a
            if t == 3:
                fs[i] = lambda x: x^a
            continue
    
        if t == 1:
            fs[i] = lambda x: (fs[i-1](x) & a)
        if t == 2:
            fs[i] = lambda x: (fs[i-1](x) | a)
        if t == 3:
            fs[i] = lambda x: (fs[i-1](x) ^ a)

    now = c
    for i in range(n):
        now = fs[i](now)
        print(now)

if __name__ == '__main__':
    main()