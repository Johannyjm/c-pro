from itertools import permutations

s, k = input().split()
k = int(k)

a = list(s)
a.sort()

res = []
for p in permutations(a):
    res.append("".join(p))

res = list(set(res))

res.sort()

print(res[k-1])