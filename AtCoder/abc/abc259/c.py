def main():
    s = input()
    t = input()

    sc = [[s[0], 1]]
    tc = [[t[0], 1]]
    for c in s:
        if c == sc[-1][0]:
            sc[-1][1] += 1
        else:
            sc.append([c, 1])
    for c in t:
        if c == tc[-1][0]:
            tc[-1][1] += 1
        else:
            tc.append([c, 1])

    if len(sc) != len(tc):
        print("No")
        exit()

    for i in range(len(sc)):
        if sc[i][1] == 1:
            if sc[i] != tc[i]:
                print("No")
                exit()
        
        else:
            if sc[i][0] != tc[i][0] or sc[i][1] > tc[i][1]:
                print("No")
                exit()
    print("Yes")

if __name__ == '__main__':
    main()