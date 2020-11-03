s = input()
n = len(s)
k = int(input())

st = set()
for i in range(n-k+1):
    # print(s[i: i+k])
    st.add(s[i: i+k])

print(len(st))