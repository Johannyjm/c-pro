from collections import defaultdict
def main():
    s = input()
    t = input()
    n = len(s)

    sc = defaultdict(int)
    tc = defaultdict(int)
    for i in range(n):
        sc[s[i]] += 1
        tc[t[i]] += 1
    
    for k in sc:
        if k == "@": continue

        if sc[k] <= tc[k]:
            tc[k] -= sc[k]
            sc[k] = 0
    
    for k in tc:
        if k == "@": continue

        if tc[k] <= sc[k]:
            sc[k] -= tc[k]
            tc[k] = 0
    
    for k in sc:
        if sc[k] == 0: continue
        if k == "@": continue

        if k in "atcoder":
            tc["@"] -= sc[k]
            sc[k] = 0

            if tc["@"] < 0:
                print("No")
                exit()
        else:
            print("No")
            exit()
    
    for k in tc:
        if tc[k] == 0: continue
        if k == "@": continue

        if k in "atcoder":
            sc["@"] -= tc[k]
            tc[k] = 0

            if sc["@"] < 0:
                print("No")
                exit()
            
        else:
            print("No")
            exit()
    
    print("Yes")


if __name__ == '__main__':
    main()