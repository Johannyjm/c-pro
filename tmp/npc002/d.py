n = int(input())
s = input()

ss = sorted(s, reverse=True)

res = 0
for i in range(n):
    if s[i] != ss[i]: res += 1
print(res)
