from collections import defaultdict
def main():
    s = input()
    t = input()
    n = len(s)

    if sorted(s) == sorted(t):
        print("Yes")
        exit()

    s_count = defaultdict(int)
    t_count = defaultdict(int)
    for i in range(n):
        s_count[s[i]] += 1
        t_count[t[i]] += 1
    
    for k in s_count:
        if k == '@': continue
        if s_count[k] == t_count[k]:
            s_count[k] = 0
            t_count[k] = 0
            continue

        if s_count[k] > t_count[k]:
            if k not in 'atcoder':
                print("No")
                exit()
            
            s_count[k] -= t_count[k]
            t_count[k] = 0

            t_count['@'] -= s_count[k]

            if t_count['@'] < 0:
                print("No")
                exit()
            
            s_count[k] = 0
        
        if s_count[k] < t_count[k]:
            s_count[k] = 0
            t_count[k] -= s_count[k]
    
    for k in t_count:
        if k == '@': continue
        if s_count[k] == t_count[k]:
            s_count[k] = 0
            t_count[k] = 0
            continue

        if t_count[k] > s_count[k]:
            if k not in 'atcoder':
                print("No")
                exit()

            t_count[k] -= s_count[k]
            s_count[k] = 0
            
            s_count['@'] -= t_count[k]

            if s_count['@'] < 0:
                print("No")
                exit()

            t_count[k] = 0

        if t_count[k] < s_count[k]:
            t_count[k] = 0
            s_count[k] -= t_count[k]

    sm = 0
    for k in s_count:
        if k == "@": continue
        sm += s_count[k]
    for k in t_count:
        if k == "@": continue
        sm += t_count[k]

    if sm == 0:
        print("Yes") 
    else:
        print("No")

if __name__ == '__main__':
    main()