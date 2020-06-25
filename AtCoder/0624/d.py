from heapq import heapify, heappush, heappop
n, m = map(int, input().split())
a = list(map(lambda x: -int(x), input().split()))

heapify(a)

for _ in range(m):
    top = heappop(a)
    top = -top // 2
    heappush(a, -top)

print(-sum(a))