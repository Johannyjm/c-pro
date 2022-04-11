n = int(input())
s = [''] * n
t = [''] * n
for i in range(n):
    si, ti = input().split()
    s[i] = si
    t[i] = ti

used = set()
for i in range(n):
    st = set()
    for j in range(n):
        if i == j: continue
        st.add(s[j])
        st.add(t[j])


