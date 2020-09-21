n = int(input())
s = [input() for _ in range(n)]
s.sort()
s.sort(key = len)

for e in s: print(e)