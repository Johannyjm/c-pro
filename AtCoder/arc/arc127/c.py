def calcones(s):
    ret = 0
    for c in s:
        if c == '1': ret += 1
        else: break
    return ret

n = int(input())
for i in range(1, n+1):
    res = calcones(str(i))
    if res != 0: print(i, res, end=', ')

