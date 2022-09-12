from itertools import permutations
from random import randint


def main():
    n, m = map(int, input().split())
    s = [''] * n
    t = [''] * m

    for i in range(n):
        s_ = input()
        s[i] = s_
    for i in range(m):
        t_ = input()
        t[i] = t_
    
    st = set(t)

    # if n == 1:
    #     if s[0] in t:
    #         print(-1)
    #     else:
    #         print(s[0])
    #     exit()

    l_sm = 0
    for i in range(n):
        l_sm += len(s[i])

    for p in permutations(range(n)):

        # if n > 1:        
        #     for i in range(1, l_sm):

        #         if n <= 2: continue
        #         for j in range(1, l_sm):

        #             if n <= 3: continue
        #             for k in range(1, l_sm):
                        
        #                 if n <= 4: continue
        #                 for l in range(1, l_sm):


        for i in range(100):
            n_under = []
            for j in range(n-1):
                n_under.append(randint(1, max(1, (16-l_sm)//(n-1))))



            cand = ''
            ptr = 0
            for pi in p:
                cand += s[pi]

                if ptr != n-1: cand += '_' * n_under[ptr]
                ptr += 1
            
            # cand = cand[:-1]

            if cand != '' and cand not in st and 3 <= len(cand) <= 16:
                print(cand)
                exit()

        # cand = ''
        # for pi in p:
        #     cand += s[pi]

        #     cand += '__'

        # cand = cand [:-2]
        # if cand != '' and cand not in st and 3 <= len(cand) <= 16:
        #     print(cand)
        #     exit()
    
    print(-1)
            

            


if __name__ == '__main__':
    main()