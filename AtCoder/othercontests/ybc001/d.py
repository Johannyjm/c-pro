from collections import deque
a, n = map(int, input().split())

def rotate(n):
    l = n // 10
    r = n % 10

    return int(str(r) + str(l))

def next_multiple(v):
    ret = []

    if v*a <= 1000000:
        ret.append(v*a)
    
    return ret

def next_rotate(v):
    ret = []
    
    if v >= 10 and v%10 != 0 and v <= 1000000:

        for _ in range(len(str(v)) - 1):
            nv = rotate(v)
            ret.append(nv)
    
    
    return ret

def main():
    INF = 1 << 60
    dist = [INF] * 1100000
    dist[1] = 0   

    q = deque()
    q.append(1)

    while len(q) > 0:
        v = q.popleft()

        for nv in next_multiple(v) + next_rotate(v):
            if dist[nv] != INF: continue

            dist[nv] = dist[v] + 1
            q.append(nv)

            if nv == n:
                print(dist[nv])
                exit()
    
    print(-1)

if __name__ == '__main__':
    main()