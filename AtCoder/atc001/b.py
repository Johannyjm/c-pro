import sys
sys.setrecursionlimit(10**6)

class UnionFind:

    def __init__(self, n: int) -> None:
        self.p = [-1] * n
        self.r = [1] * n

    def find(self, x: int) -> int:
        if(self.p[x] == -1): return x
        self.p[x] = self.find(self.p[x])
        
        return self.p[x]

    def unite(self, x: int, y: int) -> None:
        x = self.find(x)
        y = self.find(y)
        if(x == y): return
        if(self.r[x] > self.r[y]): x, y = y, x
        if(self.r[x] == self.r[y]): self.r[y] += 1

        self.p[x] = y
    
    def same(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)

    
    

def main():
    n, m = map(int, input().split())

    uf = UnionFind(n)
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        
        uf.unite(a, b)
    
    group = {}

    res = 0
    for i in range(n):
        g = uf.find(i)
        
        if(group.get(g) is None): group[g] = 1
        else: group[g] += 1

        res = max(res, group[g])
    
    print(res)

    


if __name__ == "__main__":
    main()