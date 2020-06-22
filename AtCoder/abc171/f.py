k = 1
s = 'oof'

st = set()
for i in range(26):
    txt = chr(ord('a') + i) + 'oof'
    st.add(txt)

for i in range(26):
    txt = 'o' + chr(ord('a') + i) + 'of'
    st.add(txt)

for i in range(26):
    txt = 'oo' + chr(ord('a') + i) + 'f'
    st.add(txt)

for i in range(26):
    txt = 'oof' + chr(ord('a') + i)
    st.add(txt)

for txt in list(st):
    for i in range(26):
        txt2 = chr(ord('a') + i) + txt
        st.add(txt2)
    for i in range(26):
        txt2 = txt[0] + chr(ord('a') + i) + txt[1:]
        st.add(txt2)
    for i in range(26):
        txt2 = txt[:2] + chr(ord('a') + i) + txt[2:]
        st.add(txt2)
    for i in range(26):
        txt2 = txt[:3] + chr(ord('a') + i) + txt[3:]
        st.add(txt2)
    for i in range(26):
        txt2 = txt + chr(ord('a') + i)
        st.add(txt2)


print(len(st))
# print(st)
