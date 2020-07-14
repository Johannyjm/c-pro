n = int(input())
x = input()

ones = x.count('1')
w = len(bin(ones)) - 2
li = list(x)
for i in range(n-w):
    start = i
    end = i + w
    wed = ''.join(li[start: end])
    wed = list(bin(int('0b' + wed, 2) % ones)[2: ])
    li[start: end] = wed

print(li)

# for i in range(n):
#     if(x[i]=='1'): print(ones-1)
    # else: print(ones+1)