x, y = map(int, input().split('.'))

if 0<=y<=2: print(str(x)+'-')
elif 3<=y<=6: print(str(x))
else: print(str(x)+'+')