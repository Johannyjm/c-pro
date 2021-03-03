k = int(input())
s = input()
t = input()

remain = [0] * 10
for i in range(10):
    remain[i] = k-s.count(str(i))-t.count(str(i))

def calc(cnt):
    ret = 0
    for i in range(10):
        ret += i * pow(10, cnt.count(str(i)))
    return ret

res = 0.0
comb_all = (9*k-8)*(9*k-9)
for i in range(1, 10):
    for j in range(1, 10):
        if i==j:
            if remain[i] < 2: continue
        else:
            if remain[i] == 0: continue
            if remain[j] == 0: continue
        

        if calc(s + str(i)) > calc(t + str(j)):
            if i==j:
                cnt = remain[i] * (remain[i]-1)
            else:
                cnt = remain[i] * remain[j]
            res += cnt / comb_all

print(res)