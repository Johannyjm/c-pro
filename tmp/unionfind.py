import sys
sys.setrecursionlimit(10**6)

# class UnionFind:
    
#     def __init__(self, n):
#         self.n = n
#         self.parent = [-1] * n
#         self.rank = [1] * n
    
#     def leader(self, x):
#         if self.parent[x] == -1:
#             return x
#         else:
#             self.parent[x] = self.leader(self.parent[x])
#             return self.parent[x]
    
#     def merge(self, x, y):
#         x = self.leader(x)
#         y = self.leader(y)

#         if x == y: return

#         if self.rank[x] < self.rank[y]:
#             x, y = y, x
#         if self.rank[x] == self.rank[y]:
#             self.rank[y] += 1

#         self.parent[x] = y


class UnionFind:

    def __init__(self, n):
        self.n = n
        self.parent = [-1] * n
        self.rank = [1] * n
    
    def leader(self, x):
        if self.parent[x] == -1:
            return x

        tmp = self.leader(self.parent[x])
        self.parent[x] = tmp
        return self.parent[x]

    def merge(self, x, y):
        x = self.leader(x)
        y = self.leader(y)

        if x == y: return
        if self.rank[x] > self.rank[y]:
            x, y = y, x
        if self.rank[x] == self.rank[y]:
            self.rank[y] += 1

        self.parent[x] = y


def main():
    n, q = map(int, input().split())
    uf = UnionFind(n)
    # uf.leader()
    # uf.merge()

    for _ in range(q):
        com, x, y = map(int, input().split())

        if com == 0:
            uf.merge(x, y)
        if com == 1:
            if uf.leader(x) == uf.leader(y):
                print(1)
            else:
                print(0)

if __name__ == "__main__":
    main()