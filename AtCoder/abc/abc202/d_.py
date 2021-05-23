from itertools import permutations
a = list('aaaabbb')

res = []
for i in permutations(a):
    res.append(''.join(i))

print(*sorted(list(set(res))), sep='\n')