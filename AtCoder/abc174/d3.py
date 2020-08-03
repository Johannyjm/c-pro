n = int(input())
s = input()

r = 0
w = 0
for i in range(n):
    if(s[i] == "R"): r += 1
    else: w += 1

ngr = 0
ngw = 0
for i in range(n):
    if(i < r and s[i] == 'W'): ngw += 1
    if(i >= r and s[i] == 'R'): ngr += 1

print(min(ngw, ngr) + abs(ngw-ngr))