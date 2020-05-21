import bisect
import sys
input = sys.stdin.readline
N = int(input())
A = [0 for _ in range(N)]
for n in range(N):
    A[n] = int(input())
A = A[::-1] # 数列の後ろから処理
print(A)
INF = int(1e+9 + 10)
lis = [INF] * N # 初期化
for n in range(N):
    i = bisect.bisect(lis, A[n]) # 更新すべき最小値
    lis[i] = A[n]
    print(lis)
print (bisect.bisect_left(lis, INF))