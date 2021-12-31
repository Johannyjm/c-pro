a, b = input().split()

#a = a[::-1]
#b = b[::-1]


a = reversed(a)
b = reversed(b)

for i in range(min(len(a), len(b))):
    if int(a[i]) + int(b[i]) >= 10:
        print('Hard')
        exit()
print('Easy')
