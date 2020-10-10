e = list(map(int, input().split()))
b = int(input())
l = list(map(int, input().split()))
n = 6
cnt = 0
bonus = 0
for i in range(n):
    if(l[i] in e): cnt += 1
    else:
        if(l[i] == b): bonus = 1

if(cnt == 6): print(1)
else:
    if(cnt == 5):
        if(bonus == 1): print(2)
        else: print(3)
    
    else:
        if(cnt < 3): print(0)
        else: print(8-cnt)