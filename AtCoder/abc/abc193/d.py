def calc(s, h):
    ret = 0
    for i in range(1, 10):
        cnt = s.count(str(i))
        if int(h) == i: cnt += 1
        ret += int(i) * pow(10, cnt)
    return ret

k = int(input())
s = input()
t = input()
scnt = [0] * 10
tcnt = [0] * 10
for i in range(4):
    scnt[ord(s[i])-ord('0')] += 1
    tcnt[ord(t[i])-ord('0')] += 1

res = 0
valid = 0
cnt = 0
for ta in range(1, 10):
    for ao in range(1, 10):
        if(ta == ao): 
            if(scnt[ta]+tcnt[ta]+2 > k): continue
        else:
            if(scnt[ta]+tcnt[ta]+1 > k): continue
            if(scnt[ao]+tcnt[ao]+1 > k): continue

        pt = calc(s, ta)
        pa = calc(t, ao)

        valid += 1
        print(ta, ao, pt, pa)
        if(pt > pa):
            restt = k - scnt[int(ta)]
            resta = k - tcnt[int(ao)]
            print(": o", end='\n\n')
            cnt += 1

print(valid, cnt)
print(cnt / valid)
            
