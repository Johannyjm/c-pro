x, y, z = map(int, input().split())
for w in range(100000, 0, -1):
    if x*w < z*y:
        print(w)
        exit()