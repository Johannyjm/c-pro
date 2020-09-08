# k = int(input())
# if(k%10 in (2, 4, 5, 6, 8, 0)):
#     print(-1)
#     exit()

# num = '7'
# while(True):
#     if(int(n
# 
n = int(input())
for n in range(202, 10000):
    base = 1
    while(True):
        k = n*base
        if(str(k).count('7') == len(str(k))):
            print(n, k)
            break
        
        base += 1

        if(base >= 100000):break