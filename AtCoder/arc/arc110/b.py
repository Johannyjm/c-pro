n = int(input())
t = input()
if(n == 1):
    if(t == '0'):
        print(10000000000)
    else:
        print(20000000000)
    exit()
if(n == 2):
    if(t == '01'):
        print(9999999999)
    elif(t == '00'):
        print(0)
    else:
        print(10000000000)
    exit()

# if(n < 400):
#     for i in range(n*2):
#         s = '110'*i
#         # print(i, s)
#         cnt = 0
#         for j in range(len(s)-n):
#             flg = True
#             for k in range(n):
#                 if(s[j+k]!=t[k]): 
#                     flg = False
            
#             if(flg): cnt += 1
        
#         if(len(s) > n and cnt == 0):
#             print(0)
#             exit()
#         # print(i, s, cnt)
#         if(cnt > 0):
#             print(10000000000-i+1)
#             exit()

ptr = 0
if(t[: 3] == '101'):
    ptr = 1
if(t[: 3] == '011'):
    ptr = 2

ver = ['1', '1', '0']
for i in range(n):
    if(t[i] != ver[(ptr+i)%3]):
        print(0)
        exit()

if(ptr == 0):
    d = (n+2)//3
    res = 10000000000 - d + 1
    print(res)
if(ptr == 1):
    d = n//3+1
    res = 10000000000 - d + 1
    print(res)
if(ptr == 2):
    d = (n+1)//3 + 1
    res = 10000000000 - d + 1
    print(res)
