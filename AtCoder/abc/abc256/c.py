def main():
    h1, h2, h3, w1, w2, w3 = map(int, input().split())

    # a, b, c :h1
    # d, e, f :h2
    # g, h, i :h3
    # w1 w2 w3 

    res = 0
    for a in range(1, 29):
        for c in range(1, 29):
            for g in range(1, 29):
                for i in range(1, 29):

                    b = h1 - a - c
                    d = w1 - a - g
                    f = w3 - c - i
                    h = h3 - g - i
                    eh = h2 - d - f
                    ew = w2 - b - h

                    if b>0 and d>0 and f>0 and h>0 and eh>0 and ew>0 and eh==ew:
                        res += 1
    print(res)

if __name__ == '__main__':
    main()