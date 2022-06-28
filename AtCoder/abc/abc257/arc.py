def main():
    n, k = map(int, input().split())

    if min(k, int(str(k)[::-1])) != k:
        print(0)
        exit()

    rev_k = int(str(k)[::-1])

    cand = []
    for i in range(100):
        cand.append(int(str(k) + '0' * i))
        cand.append(int(str(rev_k) + '0' * i))
    cand = list(set(cand))
    res = 0
    for elem in cand:
        if 1 <= elem <= n:
            res += 1
    # print(cand[: 10])
    print(res)




if __name__ == '__main__':
    main()