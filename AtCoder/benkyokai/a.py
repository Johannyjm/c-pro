def main():
    n = int(input())
    k = int(input())

    res = [1]

    for _ in range(n):
        
        tmp = []
        while len(res) > 0:
            val = res.pop()
            tmp.append(val * 2)
            tmp.append(val + k)
        
        res = tmp
    
    res.sort()

    print(res)

if __name__ == '__main__':
    main()