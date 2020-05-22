n = int(input())
words = input().split()

d = [-1, 1, 1, 2, -1, 4, 9, 8, -1, 3, 8, 5, 7, 9, -1, 7, 4, 0, 6, 3, -1, 5, 2, 5, -1, 0]

res = ''
for word in words:
    s = ''
    for c in word:
        if(c.islower()):
            if(d[ord(c)-97] >= 0): s += str(d[ord(c)-97])
        if(c.isupper()):
            if(d[ord(c)-65] >= 0): s += str(d[ord(c)-65])
    
    res += s
    if(s != ''): res += ' '

if(res != ''): res = res[:-1]

print(res)