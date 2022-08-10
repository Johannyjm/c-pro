import sys
sys.setrecursionlimit(10 ** 6)
from collections import deque

def main():
    
    def dfs(st: int) -> None:
        
        stack = list()

        seen[st] = True

        while len(stack) != 0:
            v = stack.pop()

            for nv in g[v]:
                if seen[nv]: continue

                seen[nv] = True
                stack.append(nv)

        
        


    n, m = map(int, input().split())

    g = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())

        a -= 1
        b -= 1

        g[a].append(b)
        g[b].append(a)
    
    seen = [False] * n # 既に訪れたか（Trueでぬられたか）
    k = 0 # 連結成分の個数
    for v in range(n):
        if seen[v]: continue

        dfs(v) # 行けるところ全部Trueに塗る
        k += 1 # 連結成分の個数　＝　「行けること全部塗る」ができた個数
    
    print(k - 1)
    


if __name__ == '__main__':
    main()