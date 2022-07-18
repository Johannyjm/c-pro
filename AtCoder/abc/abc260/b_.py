def main():
    n, x, y, z = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    s1 = [(-a[i], i) for i in range(n)]
    s2 = [(-b[i], i) for i in range(n)]
    s3 = [(-(a[i]+b[i]), i) for i in range(n)]
    s1.sort()
    s2.sort()
    s3.sort()

    res = set()
    for i in range(x):
        res.add(s1[i][1] + 1)
    
    for i in range(n):
        if y == 0: break

        if s2[i][1] + 1 not in res:
            res.add(s2[i][1] + 1)
            y -= 1

    for i in range(n):
        if z == 0: break
        
        if s3[i][1] + 1 not in res:
            res.add(s3[i][1] + 1)
            z -= 1
    
    res = sorted(res)

    print(*res, sep='\n')


        
        


if __name__ == '__main__':
    main()