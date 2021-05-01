n = int(input())
g = [list(map(int, input().split())) for _ in range(n)]
c = []
st = set()
for i in range(n):
    s = sum(g[i])
    c.append(s)
    st.add(s)
v=st[0]
if c.count(st[0]) == 1:
    v = st[1]

hval=[False]*n
wval=[False]*n

for i in range(n):
    if(sum(g[i]) == v): wval[i] = True
for j in range(n):
    for i in