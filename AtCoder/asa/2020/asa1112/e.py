s = input()

t = eval(s)
if(type(t) == type(set())): print('set')
else: print('dict')