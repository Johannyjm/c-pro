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

def main():
    n, m = map(int, input().split())
    ab = [list(map(lambda x: int(x)-1, input().split())) for _ in range(m)]

    res = 0
    for i in range(n):
        uf = UnionFind(n)
        for j, elem in enumerate(ab):
            if(i == j): continue
            uf.unite(*elem)
        
        st = set()
        for j in range(n):
            st.add(uf.find(j))
        
        if(len(st) > 1): res += 1
    
    print(res)

if __name__ == "__main__":
    main()