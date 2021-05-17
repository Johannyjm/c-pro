s = input()
res = 0
for i in range(1, 10000):
    pw = str(i)
    pw = '0' * (4-len(pw)) + pw

    valid = True
    for d in range(10):
        if s[d] == '?': continue
        if s[d] == 'o':
            if str(d) not in pw:
                valid = False
        if s[d] == 'x':
            if str(d) in pw:
                valid = False
        
    if valid:
        res += 1
print(res)