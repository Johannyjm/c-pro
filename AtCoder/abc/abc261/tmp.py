from functools import lru_cache
import sys
sys.setrecursionlimit(10 ** 6)

def main():

    @lru_cache
    def rec(i):
        if i == 0:
            return 0
        
        if i == 1:
            return abs(h[1] - h[0])
        
        ret = min(
            rec(i-1) + abs(h[i] - h[i-1]), 
            rec(i-2) + abs(h[i] - h[i-2])
        )


        return ret


    n = int(input())
    h = list(map(int, input().split()))

    print(rec(n-1))

if __name__ == '__main__':
    main()