n, m, q = map(int, input().split())
abcd = [list(map(int, input().split())) for _ in range(q)]

abcd = sorted(abcd)

for e in abcd: print(e)

a = [0 for _ in range(10)]
