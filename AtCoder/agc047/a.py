import math
n = int(input())
a = [input() for _ in range(n)]

num = []
for i in range(n):
    if('.' not in a[i]): num.append(int(a[i]) * 10000)
    else:
        str1, str2 = a[i].split('.')
        if(str2.count('0') == len(str2)):
            num.append(10000)
            continue
        while(len(str2) < 9): str2 += '0'
        if(int(str2) < 100000): continue
        if(int(str2) % 100000 != 0): continue
        #num[i] = 1000000000 // math.gcd(int(str2), 1000000000)
        #num.append(int(str1)*10000 + int(str2) // 100000)
        nn = int(str1)*10000 + int(str2) // 100000

print(num)
