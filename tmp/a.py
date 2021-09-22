# a = [
#     [1, 2, 3], 
#     [2, 3, 4], 
#     [3, 4, 5]
# ]
# b = [
#     [6, 5, 3], 
#     [2, 6, 4], 
#     [3, 7, 8]
# ]

n, m, l = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
b = [list(map(int, input().split())) for _ in range(l)]



def matmul(x, y):
    n = len(x)
    l = len(y)
    m = len(y[0])
    assert len(x[0]) == len(y), "Invalid shape!!!"

    ret = [[0] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            for k in range(l):
                ret[i][j] += a[i][k] * b[k][j]

    return ret

answer = matmul(a, b)

for elem in answer:
    print(elem)
