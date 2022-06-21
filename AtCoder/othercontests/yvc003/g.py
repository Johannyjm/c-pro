from heapq import heappush, heappop
def main():

    def check(m):
        count = 0
        for i in range(n):
            count += max(a[i] - m, 0)

        return count <= k    


    n, k = map(int, input().split())
    a = list(map(int, input().split()))


    ok = 1 << 30
    ng = -1

    while ok - ng > 1:
        mid = (ok + ng) // 2

        if check(mid):
            ok = mid
        else:
            ng = mid
    

    res = 0
    count = 0
    hp = []
    for i in range(n):
        count += max(a[i] - ok, 0)

        if a[i] > ok:
            res += (ok+1 + a[i]) * (a[i]-ok) // 2
            a[i] = ok

        heappush(hp, -a[i])
    
    
    for _ in range(k - count):
        value = heappop(hp)
        
        if value > 0:
            break

        res += -value
        heappush(hp, value+1)
    
    print(res)
    

if __name__ == '__main__':
    main()