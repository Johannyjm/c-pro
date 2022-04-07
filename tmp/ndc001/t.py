n = int(input())
a = list(map(int, input().split()))
s = sorted(a)

for i in range(n):
    for j in range(n):
        if i >= j: continue
        tmp = [e for e in a]

        tt = tmp[i]
        tmp[i] = tmp[j]
        tmp[j] = tt
        # tmp[i], tmp[j] = tmp[j], tmp[i]

        if tmp == s:
            print("Yes")
            exit()

print("No")