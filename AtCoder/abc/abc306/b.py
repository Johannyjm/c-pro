def main():
    res = 0
    base = 1
    for d in map(int, input().split()):
        res += base * d
        base *= 2
    print(res)

if __name__ == '__main__':
    main()