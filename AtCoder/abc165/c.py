n, m, q = map(int, input().split())
abcd = [list(map(int, input().split())) for _ in range(q)]

abcd = sorted(abcd)

c = dict()
for e in abcd:
    t = tuple([e[0], e[1]])
    if(t not in c): 
        c[t] = []
        c[t].append(e[2])
    else: c[t].append(e[2])

A = [0 for _ in range(11)]
for k in c:
    for e in k[c]:
        A[k[1]] = A[k[0]] + e
        