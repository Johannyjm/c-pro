k = int(input())

bk = []
while k:
    bk.append(str(k % 2))
    k //= 2

bk = reversed(bk)

bk = ''.join(bk)

bk = int(bk)

print(bk * 2)
