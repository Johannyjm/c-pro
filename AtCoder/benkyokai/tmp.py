def main():
    n, x = map(int, input().split())
    a = list(map(int, input().split()))

    for i in range(1<<n):
        use = [0] * n

        for j in range(n):

            if i & (1<<j):
                use[j] = 1
        
        # print(use)

        sm = 0
        for j in range(n):
            if use[j] == 0: continue
            sm += a[j]
        
        if sm == x:
            print("Yes")
            print(use)
            exit()
    print("No")        

if __name__ == '__main__':
    main()