import sys
sys.setrecursionlimit(10**6)

def main():

    def dfs(v):
        for c in ("a", "b", "c"):
            if len(v) != n-1:
                dfs(v + c)
            else:
                print(v + c)

    n = int(input())
    dfs("")

if __name__ == '__main__':
    main()