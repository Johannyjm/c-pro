from itertools import product
h, w, k = map(int, input().split())
c = [input() for _ in range(h)]

res = 0
for use_h in product([0, 1], repeat=h):
    for use_w in product([0, 1], repeat=w):
        
        cnt = 0
        for i in range(h):
            for j in range(w):
                # if(use_h[i] == 1 or use_w[j] == 1): continue
                # if(c[i][j] == '.'): continue

                if(use_h[i] == 0 and use_w[j] == 0 and c[i][j] == '#'): cnt += 1
        
        if(cnt == k): res += 1

print(res)