def main():
    n, m = map(int, input().split())

    res = [0] * n
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1

        res[a] += 1
        res[b] += 1
    
    print(*res, sep='\n')

if __name__ == '__main__':
    main()