from bisect import bisect_left, bisect_right

def solve(N, A, Q, queries):
    # Precompute the accumulated sleep time.
    sleep_accumulated = [0] * (N+1)
    for i in range(1, N, 2):
        sleep_accumulated[i+1] = sleep_accumulated[i-1] + A[i+1] - A[i]
    
    # flg = False
    # for i in range(N+1):
    #     if sleep_accumulated[i] != 0:
    #         flg = True
    #     if flg and sleep_accumulated[i] == 0:
    #         sleep_accumulated[i] = sleep_accumulated[i-1]
    print(sleep_accumulated)
    # exit()
    # Solve the queries.
    results = []
    for l, r in queries:
        li = bisect_right(A, l) # Get the index at which l should be inserted
        ri = bisect_left(A, r) # Get the index at which r should be inserted
        sleep_time = sleep_accumulated[ri-1] - sleep_accumulated[li]
        
        if li % 2 == 0: # l is within sleep time
            sleep_time += min(A[li], r) - l
            
        if ri % 2 == 0: # r is within sleep time
            sleep_time += r - A[ri-1]

        results.append(sleep_time)
    return results

# Read the input values
N = int(input())
A = list(map(int, input().split()))
Q = int(input())
queries = [list(map(int, input().split())) for _ in range(Q)]

# Solve and print the queries
results = solve(N, A, Q, queries)
for res in results:
    print(res)