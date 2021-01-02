n = int(input())
s = input()

res = 0
for i in range(1, n):
    l = s[: i]
    r = s[i: ]
    # print(l, r)

    cnt = 0
    for c in range(26):
        C = chr(ord('a')+c)

        if(C in l and C in r): cnt += 1
    
    res = max(res, cnt)

print(res)