class Fenwick_Tree:

    def __init__(self, n):
        self._n = n
        self.tree = [0] * n

    def add(self, idx, x):
        idx += 1

        while idx <= self._n:
            self.tree[idx-1] += x
            idx += idx & -idx
    
    def sum(self, l, r):
        return self._sum(r) - self._sum(l)

    def _sum(self, idx):
        ret = 0

        while idx > 0:
            ret += self.tree[idx-1]
            idx -= idx & -idx

        return ret

def main():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))

    bit = Fenwick_Tree(n)
    for i in range(n):
        bit.add(i, a[i])

    for _ in range(q):

        



if __name__ == "__main__":
    main()
