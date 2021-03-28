n = int(input())

for i in range(10**6 + 10):
    num = int(str(i)*2)
    
    if(num > n):
        print(i-1)
        exit()
