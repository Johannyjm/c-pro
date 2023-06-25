def main():
    n = int(input())
    s = [input() for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if i == j: continue

            cand = s[i] + s[j]

            if cand == cand[::-1]:
                print("Yes")
                exit()
    
    print("No")

if __name__ == '__main__':
    main()