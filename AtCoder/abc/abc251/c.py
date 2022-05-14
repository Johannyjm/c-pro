n = int(input())

used = set()
score_max = -1
max_index = -1
for i in range(n):
    s, t = input().split()
    t = int(t)

    if s in used: continue

    if score_max < t:
        score_max = t
        max_index = i

    used.add(s)

print(max_index + 1)