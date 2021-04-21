n = int(input())
res = []

def dfs(s, v):
    if len(s) == n:
        if v == 0:
            res.append(s)
        else:
            return
    
    else:
        if v < n:
            dfs(s + '(', v+1)
        
        if v > 0:
            dfs(s + ')', v-1)

dfs('(', 1)

for e in res:
    print(e)