n = int(input())
t = input()

for i in range(n*2):
    s = '110'*i
    cnt = 0
    for j in range(len(s)-n):
        flg = True
        for k in range(n):
            if(s[j+k]!=t[k]): 
                flg = False
        
        if(flg): cnt += 1
    
    print(i, s, cnt)
    if(cnt > 0):
        print(10000000000-i+1)
        exit()