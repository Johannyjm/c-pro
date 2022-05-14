n, w = map(int, input().split())
a = list(map(int, input().split()))

st = set()

for i in range(n):
    st.add(a[i])
    for j in range(n):
        if i == j: continue
        if a[i] + a[j] > w: continue

        st.add(a[i] + a[j])
        
        for k in range(n):
            if i == k or j == k: continue
            if a[i] + a[j] + a[k] > w: continue

            st.add(a[i] + a[j] + a[k])


print(st)
res = 0
for e in list(st):
    if e <= w: res += 1

print(res)