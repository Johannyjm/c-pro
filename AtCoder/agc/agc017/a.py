n = int(input())

even = []
odd = []

for i in range(1<<n):
    cnt = 0
    for j in range(n):
        if i & (1<<j):
            cnt += 1

    if cnt%2 == 0: even.append(i)
    else: odd.append(i)

print(len(even), len(odd))
            
