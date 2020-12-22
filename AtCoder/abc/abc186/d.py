# N = int(input())
# A = sorted(list(map(int, input().split())))

import random
import numpy as np


for _ in range(100000):
    N = random.randint(2, 20)

    A = np.random.randint(-100000000, 100000000, [N,]).tolist()

    for i in range(N):
        A[i] += 100000000

    B = [0]*(N-1)

    for i in range(N-1):
        B[i] = A[i+1]-A[i]

    sm = 0
    for i in range((N-1)//2):
        t = (i+1)*(N-(i+1))
        sm += t*(B[i]+B[N-2-i])
        # print(i,N-2-i)

    if N%2==0:
        sm += N*N/4*B[int(N//2-1)]
        # print(int(N/2-1))

    # print(int(sm))
    # print(int(sm), sum([(i*2-N+1)*a for i,a in enumerate(A)]))
    if(int(sm) != sum([(i*2-N+1)*a for i,a in enumerate(A)])):
        print(N)
        print(A)
        print(int(sm))
        print(sum([(i*2-N+1)*a for i,a in enumerate(A)]))