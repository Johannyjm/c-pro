import sys
sys.setrecursionlimit(10**6)

class DisjointSetUnion:

    def __init__(selg, n: int):
        self.n = n
        self.p = [-1 for _ in range(n)]
        self.r = [1 for _ in range(n)]

    def leader(self, x: int):
        if self.p[x] == -1:
            return x
        else:
            self.p[x] = self.leader(self.p[x])
            return self.p[x]

    def merge(self, x: int, y: int):
        x = self.leader(x)
        y = self.leader(y)

        if x == y:
            return

        if self.r[x] > self.r[y]:
            x, y = y, x

        if self.r[x] == self.r[y]:
            self.r[y] += 1

        self.p[x] = y

def main():
    n, q = map(int, input().split())

    uf = DisjointSetUnion(n)
    for _ in range(q):
        p, a, b = map(int, input().split())

        if p == 0:
            uf.merge(a, b)
        
        if p == 1:
            if uf.leader(a) == uf.leader(b):
                print("Yes")
            else:
                print("No")

if __name__ == "__main__":
    main()
