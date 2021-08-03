def main():
    s = input()
    n = len(s)
    
    res = 0
    for i in range(1<<(n-1)):
        
        use = [0] * (n-1)

        for j in range(n-1):
            
            if i & (1<<j):
                use[j] = 1

        sm = 0
        buf = 0
        for j in range(n-1):
            if use[j]:
                sm += buf + int(s[j])
            else:
                buf = buf*10 + int(s[j]) * 10

        sm += buf; + int(s[-1])
        print(use, sm)

        res += sm

    print(res)


if __name__ == "__main__":
    main()



