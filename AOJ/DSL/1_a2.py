import sys
sys.setrecursionlimit(10**6)


p = []
r = []

def init(n: int) -> None:
    global p, r
    p = [-1] * n
    r = [1] * n

def find(x: int) -> int:
    if(p[x] == -1): return x
    p[x] = find(p[x])
    return p[x]
    

def unite(x: int, y: int) -> None:
    x = find(x)
    y = find(y)
    if(x == y): return
    if(r[x] > r[y]): x, y = y, x
    if(r[x] == r[y]): r[y] += 1

    p[x] = y


def main():
    n, q = map(int, input().split())
    
    init(n)

    for _ in range(q):
        com, x, y = map(int, input().split())

        if(com == 0):
            unite(x, y)
        
        if(com == 1):
            if(find(x) == find(y)): print(1)
            else: print(0)

if __name__ == '__main__':
    main()