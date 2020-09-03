import sys
sys.setrecursionlimit(10**6)
class UnionFind:
    
    def __init__(self, n: int) -> None:
        self.p = [-1] * n

    def find(self, x: int) -> int:
        if(self.p[x] == -1): return x
        self.p[x] = self.find(self.p[x])
        return self.p[x]
    
    def unite(self, x: int, y: int) -> None:
        x = self.find(x)
        y = self.find(y)
        if(x == y): return
        
        self.p[x] = y



def main():
    n, q = map(int, input().split())
    uf = UnionFind(n)

    for _ in range(q):
        com, x, y = map(int, input().split())

        if(com == 0):
            uf.unite(x, y)
        
        if(com == 1):
            if(uf.find(x) == uf.find(y)): print(1)
            else: print(0)

if(__name__ == '__main__'):
    main()