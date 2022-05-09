def main():
    n, a, b = map(int, input().split())
    board = [[''] * (n*b) for _ in range(n*a)]
    for i in range(n*a):
        for j in range(n*b):

            j_idx = j
            i_idx = i
            j_idx //= b
            i_idx //= a

            if(i_idx + j_idx) % 2 == 0:
                board[i][j] = '.'
            else:
                board[i][j] = '#'
    
    for i in range(len(board)):
        print(*board[i], sep='')


if __name__ == '__main__':
    main()