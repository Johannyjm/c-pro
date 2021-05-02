from collections import deque
s = input()
flip = False

res = deque()
for c in s:
    if c == 'R':
        flip ^= True
    else:
        if flip:
            if len(res) > 0 and res[0] == c:
                res.popleft()
            else:
                res.appendleft(c)
        else:
            if len(res) > 0 and res[-1] == c:
                res.pop()
            else:
                res.append(c)
res = "".join(res)

if flip:
    res = res[::-1]

print(res)