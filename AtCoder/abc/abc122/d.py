s = ['A', 'G', 'C', 'T']

def check(st):
    if('AGC' in st): return True
    if('AGC' in st[1]+st[0]+st[2]+st[3]+st[4]): return True
    if('AGC' in st[0]+st[2]+st[1]+st[3]+st[4]): return True
    if('AGC' in st[0]+st[1]+st[3]+st[2]+st[4]): return True
    if('AGC' in st[0]+st[1]+st[2]+st[4]+st[3]): return True
    
    return False

cnt = 0
for a in s:
    for b in s:
        for c in s:
            for d in s:
                for e in s:
                    st = a+b+c+d+e
                    if(check(st)):
                        print(st)
                        cnt += 1

print(cnt)
print(4**5-cnt)