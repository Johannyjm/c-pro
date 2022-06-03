n, m = map(int, input().split())

g = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())

    g[a].append(b)
    g[b].append(a)

res = 0
res_idx = [-1, -1, -1]
for i in range(n):
    for j in range(n):
        for k in range(n):

            if not (i < j < k): continue

            lang_set = set()

            for nv in g[i]:
                lang_set.add(nv)
            for nv in g[j]:
                lang_set.add(nv)
            for nv in g[k]:
                lang_set.add(nv)

            # res = max(res, len(lang_set))
            if len(lang_set) > res:
                res = len(lang_set)
                res_idx = [i, j, k]
print(*res_idx)