n = int(input())
a = list(map(int, input().split()))

if(0 in a):
    print(0)
    exit()

res = 1
for aa in a:
    res *= aa
    if(res > 1000000000000000000):
        print(-1)
        exit()

print(res)