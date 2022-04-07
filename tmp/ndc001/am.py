s, t = input().split()
a, b = map(int, input().split())
u = input()

count = {}
count[s] = a
count[t] = b
count[u] -= 1

print(count[s], count[t])