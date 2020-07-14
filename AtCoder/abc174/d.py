def f(n):
    ret = 0
    while(n):
        n = n%bin(n).count('1')
        ret += 1
    return ret

cut = 50

m = int(input())
x = input()
if(len(x) > cut): x = x[-cut: ]

n = int('0b' + x, 2)
large = f(n)
for i in range(m):
    if(m > cut):
        if(i < m-cut): print(large)
        else:
            num = n ^ (1 << (m-i-1))
            print(f(num))

    
    num = n ^ (1 << (m-i-1))
    print(f(num))
