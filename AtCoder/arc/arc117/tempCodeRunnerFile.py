n = int(input())

a = [6, 10, 14, 22, 1155]
st = set(a)
for e in a:
    for i in range(2, 10000//e + 2):
        if e == 1155 and i == 2: continue
        val = e * i
        if val > 10000: continue

        if val in st: continue
        a.append(val)
        st.add(val)

print(*a[: n])