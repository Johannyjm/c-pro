dy = (0, 1, 1, 1, 0, -1, -1, -1)
dx = (1, 1, 0, -1, -1, -1, 0, 1)

def main():
    h, w = map(int, input().split())
    s = [input() for _ in range(h)]

    res = [[-1]*w for _ in range(h)]
    
    for i in range(h):
        for j in range(w):

            if(s[i][j] == '#'): continue

            counter = 0
            for di in range(8):

                ni = i + dy[di]
                nj = j + dx[di]

                if ni<0 or ni>=h or nj<0 or nj>=w: continue

                if s[ni][nj] == '#':
                    counter += 1
            
            res[i][j] = counter
    

    for i in range(h):
        for j in range(w):

            if res[i][j] == -1:
                print('#', end='')
            else:
                print(res[i][j], end='')
            
        print()




if __name__ == '__main__':
    main()