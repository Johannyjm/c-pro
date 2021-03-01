s = input()
n = len(s)

cnt = [0] * 26
res = 0
for i in reversed(range(1, n)):
    if i<n-1 and s[i]==s[i+1]:
        cnt[ord(s[i])-ord('a')] += 1
        continue
    if s[i] == s[i-1]:
        res += n-1 - i - cnt[ord(s[i])-ord('a')]
        cnt = [0] * 26
        cnt[ord(s[i])-ord('a')] = n-i
    else:
        cnt[ord(s[i])-ord('a')] += 1

print(res)
