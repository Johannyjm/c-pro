def main():
    n = int(input())
    s = [input() for _ in range(n)]

    res = 1 << 60
    for i in range(10):

        used = [False] * n
        sm = 0
        flg = False

        while True:
            for j in range(10):
                for k in range(n):
                    if used[k]: continue

                    if s[k][j] == str(i):
                        used[k] = True
                        if all(used):
                            flg = True
                            sm += j
                            break
                        break
                if flg:
                    break
            if flg:
                break
            sm += 10
        
        res = min(res, sm)
        # print(i, sm)


    print(res)


if __name__ == '__main__':
    main()