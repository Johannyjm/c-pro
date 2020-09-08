n, l = map(int, input().split())

a = [list(input()) for _ in range(l)]
y = list(input())
s = y.index('o')

now = [l-1, s]
while(now[0] >= 0):
    j = now[1]
    i = now[0]

    for dj in [-1, 1]:
        nj = j + dj
        if(nj<0 or nj>=2*n-1): continue
        if(a[i][nj] == '-'): 
            j = nj + dj
            break
    i -= 1
    now = [i, j]

print((now[1]+1)//2 + 1)


