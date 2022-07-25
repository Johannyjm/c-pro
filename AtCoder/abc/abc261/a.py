def main():
    a, b, c, d = map(int, input().split())

    e = [0] * 110
    for i in range(a, b):
        e[i] += 1

    for i in range(c, d):
        e[i] += 1
    
    print(e.count(2))

if __name__ == '__main__':
    main()