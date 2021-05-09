n = int(input())
a = []
a.append(3*5*7*11)
a.append(2*5)
a.append(2*7)
if(n == 3):
    print(*a)
    exit()
a.append(2*11)
if(n == 4):
    print(*a)
    exit()
a.append(2*3)
if(n == 5):
    print(*a)
    exit()


primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
m = len(primes)
cnt = 5
st = set(a)

for i in range(1<<m):
    use = [False] * m
    for j in range(m):
        if(i & (1<<j)):
            use[j] = True
    
    if not use[0]: continue
    flg = True
    for j in range(1, 5):
        if use[j]: flg = False
    
    if flg: continue
    
    base = 1
    for j in range(m):
        if(use[j]): base *= primes[j]
    
    if base > 10000: continue
    if base in st: continue

    a.append(base)
    st.add(base)
    cnt += 1
    if cnt == n: break

    for j in range(15):
        for k in range(15):
            for l in range(15):
                if j==0 and k==0 and l==0: continue

                val = base * pow(2, j) * pow(3, k) * pow(5, l)

                if val > 10000: continue
                if val in st: continue

                a.append(val)
                st.add(val)
                cnt += 1

                if cnt == n:
                    print(*a)
                    exit()


# for i in range(1, 100):
#     for j in range(1, 100):
#         if i==1 and j==1: continue
#         val = 2**i * 3**j
#         if val > 10000: continue
#         if val in st: continue
#         a.append(val)
#         st.add(val)
        # print(val, end=' ')


# for i in range(1, 100):
#     for j in range(1, 100):
#         if i==1 and j==1: continue
#         val = 2**i * 3**j
#         if val > 10000: continue
#         if val in st: continue
#         a.append(val)
#         st.add(val)
#         # print(val, end=' ')

# for i in range(1, 100):
#     for j in range(1, 100):
#         if i==1 and j==1: continue
#         val = 2**i * 5**j
#         if val > 10000: continue
#         if val in st: continue
#         a.append(val)
#         st.add(val)

# for i in range(1, 100):
#     for j in range(1, 100):
#         if i==1 and j==1: continue
#         val = 2**i * 7**j
#         if val > 10000: continue
#         if val in st: continue
#         a.append(val)
#         st.add(val)

# for i in range(1, 100):
#     for j in range(1, 100):
#         if i==1 and j==1: continue
#         val = 2**i * 11**j
#         if val > 10000: continue
#         if val in st: continue
#         a.append(val)
#         st.add(val)


print(len(a))
print(*a)

from math import gcd
g = a[0]
for i in range(1, len(a)):
    g = gcd(g, a[i])
print(g)
