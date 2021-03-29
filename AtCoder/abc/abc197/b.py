
def main():
    h, w, y, x = map(int, input().split())
    x -= 1
    y -= 1
    s = [input() for _ in range(h)]

    dy = (0, 1, 0, -1)
    dx = (1, 0, -1, 0)

    res = 1
    for di in range(4):
        cy = y
        cx = x
        while True:
            ny = cy + dy[di]
            nx = cx + dx[di]

            if ny>=h or ny<0 or nx>=w or nx<0: break
            if s[ny][nx] == '#': break
            
            res += 1
            cy = ny
            cx = nx

    print(res)

if __name__ == "__main__":
    main()
