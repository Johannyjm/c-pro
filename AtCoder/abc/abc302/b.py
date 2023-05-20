dy = (0, 1, 1, 1, 0, -1, -1, -1)
dx = (1, 1, 0, -1, -1, -1, 0, 1)
snuke = "snuke"

def valid(s, h, w, y, x, di):

    found = True
    for g in range(1, 5):
        ny = y + dy[di] * g
        nx = x + dx[di] * g

        if ny<0 or ny>=h or nx<0 or nx>=w:
            return False

        if s[ny][nx] != snuke[g]:
            found = False
    
    return found

def main():
    h, w = map(int, input().split())
    s = [input() for _ in range(h)]

    for i in range(h):
        for j in range(w):
            if s[i][j] != "s": continue

            for di in range(8):
                if valid(s, h, w, i, j, di):
                    # print(i, j, di)
                    for g in range(5):
                        print(i + dy[di]*g + 1, j + dx[di]*g + 1)
                    exit()

if __name__ == '__main__':
    main()