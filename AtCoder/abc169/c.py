a, b = input().split()
a = int(a)
b = b.replace('.', '')
b = int(b)
res = str(a*b)

if(len(res) <= 2): print(0)
else: print(res[:-2])
