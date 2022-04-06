n = int(input())
a = list(map(int, input().split()))

if list(range(1, n+1)) == sorted(a):
    print("Yes")
else:
    print("No")