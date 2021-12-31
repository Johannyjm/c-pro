s = input()
t = input()

st = set()
for i in range(len(s)):
    st.add(ord(s[i]) - ord(t[i]))

if len(st) == 1:
    print('Yes')
    exit()

print('No')
