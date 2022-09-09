H, W = map(int, input().split())
grid = [list(input()) for _ in range(H)]

x = 0
y = 0
# visited = [[y, x]]
visited = set()
visited.add((y, x))

while True:
    if grid[y][x] == 'U':
        if y == 0:
            print(y+1, x+1)
            exit()
        else:
            y -= 1
            if (y, x) in visited:
                print(-1)
                exit()
            visited.add((y, x))
            continue
    if grid[y][x] == 'D':
        if y == H-1:
            print(y+1, x+1)
            exit()
        else:
            y += 1
            if (y, x) in visited:
                print(-1)
                exit()
            visited.add((y, x))
            continue
    if grid[y][x] == 'L':
        if x == 0:
            print(y+1, x+1)
            exit()
        else:
            x -= 1
            if (y, x) in visited:
                print(-1)
                exit()
            visited.add((y, x))
            continue
    if grid[y][x] == 'R':
        if x == W-1:
            print(y+1, x+1)
            exit()
        else:
            x += 1
            if (y, x) in visited:
                print(-1)
                exit()
            visited.add((y, x))
            continue


