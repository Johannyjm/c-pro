from itertools import permutations

def main():
    n, m = map(int, input().split())
    s = [input() for _ in range(n)]

    for p in permutations(s):
        # print(p)

        valid = True
        for i in range(1, n):
            s1 = p[i-1]
            s2 = p[i]

            count = 0
            for j in range(m):
                if s1[j] != s2[j]:
                    count += 1
                  
            if count > 1:
                valid = False
        
        if valid:
            print("Yes")
            exit()
    
    print("No")


if __name__ == '__main__':
    main()