import random
import numpy as np

n = 4

aa = []
bb = []

for i in range(4):
    
    a = -1
    b = -1
    while(True):
        a = random.randint(1, 10)
        b = random.randint(1, 10)
        if(a <= b): break
    
    aa.append(a)
    bb.append(b)

print(n)
for i in range(n): print(aa[i], bb[i])
print()

st = set()
for i in range(aa[0], bb[0]+1):
    for j in range(aa[1], bb[1]+1):
        for k in range(aa[2], bb[2]+1):
            for l in range(aa[3], bb[3]+1):
                
                # print(i, j, k, l, np.median([i, j, k, l]))
                st.add(np.median([i, j, k, l]))

print(st)

aa.sort()
bb.sort(reverse=True)

idx = (n-1)//2
print(idx)
l = aa[idx] + aa[idx+1]
r = bb[idx] + bb[idx+1]
print(aa[idx], aa[idx+1])
print(bb[idx], bb[idx+1])

print(len(st))
# print(bb[(n-1)//2]+bb[((n-1)//2)+1] - aa[(n-1)//2]-aa[((n-1)//2)+1] + 1)
print(r - l + 1)