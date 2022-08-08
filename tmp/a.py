def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    count = dict()
    res = -1
    for elem in a:

        if elem - k in count:
            count[elem] = count[elem - k] + 1
            res = max(res, count[elem])
        else:
            count[elem] = 1
    
    print(res)

if __name__ == '__main__':
    main()