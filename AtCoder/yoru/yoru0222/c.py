from collections import deque
n = int(input())
a = list(map(int, input().split()))
dq = deque()

for i in range(n):
    if(i%2 == 0):
        dq.append(a[i])
    else:
        dq.appendleft(a[i])

res = list(dq)
if(n%2 == 1): res = res[::-1]
print(*res)
