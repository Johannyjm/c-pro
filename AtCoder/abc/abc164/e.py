import heapq
n, k = map(int, input().split())
a = list(map(lambda x: -int(x), input().split()))

heapq.heapify(a)
for i in range(k):
    longest = heapq.heappop(a)
    longest /= 2
    heapq.heappush(a, longest)
    heapq.heappush(a, longest)

    if(abs(longest) < 1): break
print(a)
res = heapq.heappop(a)
if res-int(res) == 0: print(-int(res))
else: print(-int(res)+1)
