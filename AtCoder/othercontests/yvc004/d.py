def main():
    x, y = map(int, input().split())

    res = 0
    now = x
    while now <= y:
        now *= 2
        res += 1
    
    print(res)

if __name__ == '__main__':
    main()