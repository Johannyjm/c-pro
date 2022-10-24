n = int(input())
b = list(map(int, input().split()))
b.sort()

if n == 2:
    print(sum(b)//2)
    exit()

diff = [0] * (n-1)
for i in range(n-1):
    diff[i] = b[i+1] - b[i]

# print(diff)
print(b[diff.index(max(diff))] + min(diff))