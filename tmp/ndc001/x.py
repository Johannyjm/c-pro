n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
count = {}
for e in a:
    if e in count : count[e] += 1
    else: count[e] = 1

for i in range(m):
    if b[i] not in count or count[b[i]] == 0:
        print("No")
        exit()
    
    count[b[i]] -= 1
print("Yes")