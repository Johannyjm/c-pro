def main():
    n = int(input())

    rl = [0] * n
    for i in range(n):
        x, le = map(int, input().split())

        r = x + le
        l = x - le

        rl[i] = (r, l)
    
    rl.sort()

    now = -(1<<60)
    res = 0
    for i in range(n):

        if rl[i][1] >= now:
            res += 1
            now = rl[i][0]
    
    print(res)

if __name__ == '__main__':
    main()