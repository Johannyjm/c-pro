t = int(input())

for _ in range(t):
    n = int(input())
    if n % 4 == 2: print('Same')
    elif n % 2 == 0: print('Even')
    else: print('Odd')