h, w, k = map(int, input().split())
c = [input() for _ in range(h)]


res = 0
for ih in range(1<<h):
    for iw in range(1<<w):

        h_use = [False] * h # 1: use
        w_use = [False] * w # 1: use
        for jh in range(h):
            if(ih & (1 << jh) != 0): h_use[jh] = True
        
        for jw in range(w):
            if(iw & (1 << jw) != 0): w_use[jw] = True

        cnt = 0
        for i in range(h):
            for j in range(w):
                
                if(h_use[i] or w_use[j]): continue
                if(c[i][j] == '.'): continue
                
                cnt += 1
        
        if(cnt == k): res += 1

print(res)