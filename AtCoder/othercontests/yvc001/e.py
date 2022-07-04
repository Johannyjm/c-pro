def main():

    n = int(input())
    a = list(map(int, input().split()))
    count = {}
    for e in a:
        if e in count : count[e] += 1
        else: count[e] = 1

    flg = True
    if n % 2 == 0:
        # odd num * 2 to n-1 
        for i in range(1, n, 2):
            if i not in count or count[i] != 2:
                flg = False
                break
    
    else:
        # one 0 and even num * 2 to n-1
        if 0 not in count:
            flg = False
        else:
            count[0] += 1
        
        for i in range(0, n, 2):
            if i not in count or count[i] != 2:
                flg = False
                break
        
    if flg:
        print(pow(2, n//2, 1000000007))
    else:
        print(0)


if __name__ == '__main__':
    main()