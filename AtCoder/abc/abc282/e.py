class UnionFind:

    def __init__(self, n):
        self.p = [-1] * n
        self.r = [1] * n

    def leader(self, x):
        if self.p[x] == -1:
            return x
        else:
            parent = self.leader(self.p[x])
            self.p[x] = parent
            return parent

    def merge(self, x, y):
        x = self.leader(x)
        y = self.leader(y)

        if x == y:
            return

        if self.r[x] > self.r[y]:
            x, y = y, x

        if self.r[x] == self.r[y]:
            self.r[y] += 1

        self.p[x] = y
    
n, m = map(int, input().split())
a = list(map(int, input().split()))

INF = 1 << 60
costs = [[-INF] * n for _ in range(n)]
edges = []
for i in range(n):
    for j in range(n):
        
        if i == j: continue

        costs[i][j] = (pow(a[i], a[j], m) + pow(a[j], a[i], m)) % m
        edges.append((costs[i][j], (i, j)))

edges.sort(reverse=True)

res = 0
uf = UnionFind(n)
for edge in edges:
    cost, (u, v) = edge

    if uf.leader(u) != uf.leader(v):
        uf.merge(u, v)
        res += cost

print(res)
