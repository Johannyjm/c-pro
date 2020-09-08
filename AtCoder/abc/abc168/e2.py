n = int(input())
ab = [list(map(int, input().split())) for _ in range(n)]

mp = dict()
for i in range(n):
    a, b = ab[i]
    mp[-b/a] = i

hate = [-1 for _ in range(n)]
for i in range(n):
    a, b = ab[i]
    if(mp.get(a/b) is not None):
        if(hate[mp[-b/a]] == -1): hate[[-b/a]] = 1
        else: hate[mp[-b/a]] += 1
    
print(hate)