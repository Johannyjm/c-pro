def one(x, y):
    return [y, -x]

def two(x, y):
    return [-y, x]

def three(x, y, ax):
    return [ax + (ax - x), y]

def four(x, y, ax):
    return [x, ax + (ax - y)]

n = int(input())
xy = [list(map(int, input().split())) for _ in range(n)]
m = int(input())
op = [input() for _ in range(m)]
q = int(input())
ab = [list(map(int, input().split())) for _ in range(q)]

abi = [0] * q
for i in range(q):
    abi = [ab[0], ab[1], i]

abi.sort()

fs = []
for i in range(m):
    ope = op[i]
    if(len(ope) == 1): cmd = int(ope)
    else cmd, p = map(int, ope)

    if(cmd == 1): fs.append(one)