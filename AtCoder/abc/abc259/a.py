class UnionFind:

    def __init__(self, n: int) -> None:
        self.parent = [-1] * n
    
    def find(self, x: int) -> int:
        if self.parent[x] == -1:
            return x
        
        return self.find(self.parent[x])
    
    def union(self, x: int, y: int) -> None:
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return
        
        self.parent[x] = y
    

def main():
    n, q = map(int, input().split())

    uf = UnionFind(n)
    for _ in range(q):
        p, a, b = map(int, input().split())
        a -= 1
        b -= 1

        if p == 0:
            uf.union(a, b)
        
        if p == 1:
            if uf.find(a) == uf.find(b):
                print("Yes")
            else:
                print("No")

if __name__ == '__main__':
    main()