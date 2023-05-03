def main():
    h, w = map(int, input().split())
    a = [input() for _ in range(h)]
    b = [input() for _ in range(h)]

    for s in range(h):
        a_s = ["" for _ in range(h)]
        for i in range(h):
            a_s[i] = a[(i+s)%h]
        
        # print(*a_s, sep='\n')
        # print()
        

        for t in range(w):

            a_s_t = a_s.copy()
            for i in range(h):
                st = a_s_t[i]                
                
                for j in range(t):
                    st = st[1: ] + st[0]
                
                a_s_t[i] = st
            
            # print(*a_s_t, sep='\n')
            # print()

            if b == a_s_t:
                # print(s, t)
                print("Yes")
                exit()


    print("No")

if __name__ == '__main__':
    main()