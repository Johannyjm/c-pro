a, b, w = map(int, input().split())
w *= 1000

ok = []
for i in range(1000001):
    if a*i <= w and w <= b*i:
        ok.append(i)

if len(ok)==0: print("UNSATISFIABLE")
else: print(min(ok), max(ok))
