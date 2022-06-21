def main():
    n, q = map(int, input().split())
    s = input()
    n = len(s)

    cumsum = [0] * n

    for i in range(1, n):
        cumsum[i] += cumsum[i-1]
        if s[i-1]=='A' and s[i]=='C':
            cumsum[i] += 1
    
    # print(cumsum)

    for _ in range(q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1

        print(cumsum[r] - cumsum[l])

if __name__ == '__main__':
    main()