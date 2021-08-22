n, q = map(int, input().split())
s = input()

for _ in range(q):
    l, r = map(int, input().split())
    l -= 1
    r -= 1

    sub = s[l: r+1]
    print(sub.count('AC'))

