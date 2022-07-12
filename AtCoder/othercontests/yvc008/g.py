def main():
    s = input()

    candidates = set()
    for i in range(1<<4):
        use = [''] * 4
        for j in range(4):
            if i & (1<<j):
                use[j] = 'A'
        
        candidates.add(use[0] + 'KIH' + use[1] + 'B' + use[2] + 'R' + use[3])
    
    if s in candidates:
        print("YES")
    else:
        print("NO")


if __name__ == '__main__':
    main()