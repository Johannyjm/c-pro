n = int(input())
a = list(map(int, input().split()))

res = 0
while True:
    # even check 
    flg = True # True if all elements are even
    for elem in a:
        if elem % 2 == 1:
            flg = False

    if flg: # The case all elements are even
        res += 1
        for i in range(n):
            a[i] //= 2
    
    else:
        break

print(res)
        
    