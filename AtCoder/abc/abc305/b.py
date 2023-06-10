def main():
    p, q = input().split()

    distances = {'A': 3, 'B': 1, 'C': 4, 'D': 1, 'E': 5, 'F': 9}
    if q < p:
        p, q = q, p
    
    res = 0
    for c in range(ord(p), ord(q)):
        res += distances[chr(c)]
    
    print(res)


if __name__ == '__main__':
    main()