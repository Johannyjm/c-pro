from itertools import product

def main():
    n, x = map(int, input().split())
    a = list(map(int, input().split()))

    for use in product([0, 1], repeat=n):
        
        total = 0
        for j in range(n):
            if use[j]:
                total += a[j]
        
        if total == x:
            print("Yes")
            exit()
    
    print("No")


    for i in range(1<<n):
        use = [False] * n # 使う:True 使わない:False

        for j in range(n):
            if i & (1<<j):
                use[j] = True
        
        total = 0
        for j in range(n):
            if use[j]:
                total += a[j]
        
        if total == x:
            print("Yes")
            exit()
    
    print("No")

if __name__ == '__main__':
    main()