o = input()
e = input()
res = ''
for i in range(len(o) + len(e)):
    if i%2 == 0:
        res += o[i//2]
    else:
        res += e[i//2]
print(res)