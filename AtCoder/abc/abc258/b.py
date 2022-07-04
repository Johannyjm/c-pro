dx = (1, 1, 0, -1, -1, -1, 0, 1)
dy = (0, 1, 1, 1, 0, -1, -1, -1)

def main():
    n = int(input())
    a = [input() for _ in range(n)]

    res = 0
    for i in range(n):
        for j in range(n):

            for di in range(8):
                
                cand = 0
                for gain in range(n):
                    ci = i + dy[di] * gain + n*10
                    cj = j + dx[di] * gain + n*10

                    # if ci >= n: ci = 0
                    # if ci < 0: ci = n-1
                    # if cj >= n: cj = 0
                    # if cj < 0: cj = n-1

                    ci %= n
                    cj %= n

                    cand *= 10
                    cand += int(a[ci][cj])
                
                res = max(res, cand)

                # print(i, j, di, cand)
    
    print(res)


if __name__ == '__main__':
    main()