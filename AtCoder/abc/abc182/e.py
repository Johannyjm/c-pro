h, w, n, m = map(int, input().split())
field = [[0 for _ in range(w)] for _ in range(h)]
for _ in range(n):
    a, b = map(int, input().split())
    field[a-1][b-1] = 1
for _ in range(m):
    c, d = map(int, input().split())
    field[c-1][d-1] = 2
 
# ランプが光れば1を入れる配列
lamp = [[0 for _ in range(w)] for _ in range(h)]
 
# 右から左
for y in range(h):
    flag = False
    for x in range(w):
        if field[y][x] == 1:
            flag = True
        elif field[y][x] == 2:
            flag = False
        if flag:
            lamp[y][x] = 1

    flag = False
    for x in range(w-1, -1, -1):
        if field[y][x] == 1:
            flag = True
        elif field[y][x] == 2:
            flag = False
        if flag:
            lamp[y][x] = 1
 
# 上から下
for x in range(w):
    flag = False
    for y in range(h):
        if field[y][x] == 1:
            flag = True
        elif field[y][x] == 2:
            flag = False
        if flag:
            lamp[y][x] = 1
 

    flag = False
    for y in range(h-1, -1, -1):
        if field[y][x] == 1:
            flag = True
        elif field[y][x] == 2:
            flag = False
        if flag:
            lamp[y][x] = 1
 
print(sum([sum(i) for i in lamp]))