# l = 15

for l in range(16, 64):
    cnt = 0
    for a in range(l+1):
        for b in range(l+1):
            if(a+b > l): continue
            if(a^b == a+b):
                # print()
                # print('a', a, str(bin(a).replace('b', '0').zfill(6)))
                # print('b', b, str(bin(b).replace('b', '0').zfill(6)))
                cnt += 1
    print(l, cnt)