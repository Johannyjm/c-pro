import numpy as np
n = int(input())
a = np.zeros([n, n])
for i in range(n):
    for j in range(n):
        a[i][j] = n*i + j

# print(a)

q = int(input())

for _ in range(q):
    query = input()
    if(len(query) == 1): a = a.T
    
    else:
        cmd, x, y = map(int, query.split())
        x -= 1
        y -= 1

        if(cmd == 1 or cmd == 2):
            arr = np.arange(n)
            tmp = arr[x]
            arr[x] = arr[y]
            arr[y] = tmp

            if(cmd == 1):
                a = a[arr, :]
            else:
                a = a[:, arr]
        if(cmd == 4):
            print(int(a[x][y]))

