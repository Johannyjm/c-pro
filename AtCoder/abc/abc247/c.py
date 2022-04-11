n = int(input())
prev = '1'
res = '1'
for i in range(1, n):
    res += ' ' + str(i+1) + ' ' + prev
    prev = res
print(res)
