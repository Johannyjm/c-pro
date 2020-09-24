s = input()
n = len(s)
for i in range(n):
    for j in range(n):
        if(i>j): continue
        if(s[: i] + s[j: ] == 'keyence'):
            print("YES")
            exit()
print("NO")
        