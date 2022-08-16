def main():
    h1, w1 = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(h1)]
    h2, w2 = map(int, input().split())
    b = [list(map(int, input().split())) for _ in range(h2)]

    n = h1 + w1

    for i in range(1<<n):
        use = [False] * n

        for j in range(n):
            if i & (1<<j):
                use[j] = True

        cand = []
        for j in range(h1):
            if not use[j]: continue

            row = []            
            for k in range(w1):
                if not use[h1 + k]: continue

                row.append(a[j][k]) 
            cand.append(row)

        if cand == b:
            print("Yes")
            exit()               
                
    print("No")        

if __name__ == '__main__':
    main()