a, b = map(int, input().split())
x = a+b
y = b

if x>=15 and y>=8: print(1)
elif x>=10 and y>=3: print(2)
elif x>=3: print(3)
else: print(4)
