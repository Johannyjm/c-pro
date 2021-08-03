from itertools import permutations

def main():
    
    n, m = map(int, input().split())

    dist = [[-1] * n for _ in range(n)]

    for _ in range(m):
        s, t, d = map(int, input().split())

        dist[s][t] = d
    

    INF = 1<<60
    res = INF
    for p in permutations(range(n)):
        
        valid = True

        for i in range(n-1):
            # from: p[i], to: p[i+1]

            if dist[p[i]][p[i+1]] == -1:
                valid = False

        if dist[p[-1]][p[0]] == -1:
            valid = False

        if not valid:
            continue


        distance = 0

        for i in range(n-1):
            distance += dist[p[i]][p[i+1]]

        distance += dist[p[-1]][p[0]]

        res = min(res, distance)

    
    if res == INF:
        res = -1

    print(res)

if __name__ == "__main__":
    main()
