def main():
    n, x, y, z = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    scoresx = []
    for i in range(n):
        scoresx.append((a[i], -(i+1)))
    
    scoresx.sort(reverse=True)

    # print(scores)

    ps = set()
    nx = ny = nz = 0
    for i in range(n):
        if nx == x:
            break
        if -scoresx[i][1] not in ps:
            ps.add(-scoresx[i][1])
            nx += 1
    
    scoresy = []
    for i in range(n):
        scoresy.append((b[i], -(i+1)))
    
    scoresy.sort(reverse=True)

    for i in range(n):
        if ny == y:
            break
        if -scoresy[i][1] not in ps:
            ps.add(-scoresy[i][1])
            ny += 1

    scoresz = []
    for i in range(n):
        scoresz.append((a[i]+b[i], -(i+1)))
    
    scoresz.sort(reverse=True)

    for i in range(n):
        if nz == z:
            break
        if -scoresz[i][1] not in ps:
            ps.add(-scoresz[i][1])
            nz += 1


    res = sorted(list(ps))
    print(*res, sep='\n')


if __name__ == '__main__':
    main()