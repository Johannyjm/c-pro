n, k = map(int, input().split())
a = list(map(int, input().split()))

sorted_a = sorted(a, reverse=True)
abs_a = sorted(a, reverse=True, key=lambda x: abs(x))

# print(sorted_a)
# print(abs_a)

neg_cnt = 0
neg_idx = []
pos_idx = []
zero_idx = []
for i in range(n):
    if(abs_a[i] < 0):
        neg_cnt += 1
        neg_idx.append(i)
    elif(abs_a[i] > 0):
        pos_idx.append(i)
    else:
        zero_idx.append(i)

if(n - len(zero_idx) < k):
    print(0)
    exit()
else:
    if(n - len(zero_idx) == k and neg_cnt % 2 == 1):
        print(0)
        exit()

mod = 1000000007

if(neg_cnt == n and k%2 == 1):
    res = 1
    for i in range(1, k+1):
        res *= abs_a[-i]
        res %= mod

    print(res)
    exit()


if(neg_cnt == 0):
    res = 1
    for i in range(k):
        res *= abs_a[i]
        res %= mod

    print(res)


else:
    res = 1
    n_cnt = 0
    last_p = -1
    last_n = -1
    for i in range(k):
        res *= abs_a[i]
        res %= mod

        if(abs_a[i] < 0): 
            n_cnt += 1
            last_n = i
        else:
            last_p = i
    
    if(n_cnt%2 == 0):
        print(res)
    else:
        if(last_p == -1):
            print(res)
        else:
            if(abs_a[k-1] < 0):
                nxt_p = -1
                for i in range(k, n):
                    if(abs_a[i] > 0):
                        nxt_p = i
                        break
                    
                if(nxt_p != -1):
                    res = 1
                    for i in range(k-1):
                        res *= abs_a[i]
                        res %= mod
                    res *= abs_a[nxt_p]
                    res %= mod
                    print(res)
                    exit()
                
                else:
                    res = 1
                    for i in range(k):
                        if(i == last_p): continue
                        res *= abs_a[i]
                        res %= mod
                    res *= abs_a[k]
                    res %= mod

                    print(res)
                    exit()



