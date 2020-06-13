n = int(input())
a = list(map(int, input().split()))

for i in range(n):
    print(i+i*a[i])
