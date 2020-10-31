n, k = map(int, input().split())

res = 0
for a in range(1, n+1):
    for b in range(1, n+1):
        for c in range(1, n+1):
            for d in range(1, n+1):

                if(a+b-c-d==k):
                    print(a, b, c, d)
                    res += 1

print(res)