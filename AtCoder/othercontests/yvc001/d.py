def main():

    n, q = map(int, input().split())
    parent = [-1] * n
    child = [-1] * n
    rdict = {}

    resq = [0] * q
    for qi in range(q):
        cmd = list(map(int, input().split()))
        
        if cmd[0] == 1:
            _, x, y = cmd
            x -= 1
            y -= 1
            parent[y] = x
            child[x] = y
        
        if cmd[0] == 2:
            _, x, y = cmd
            x -= 1
            y -= 1
            parent[y] = -1
            child[x] = -1
            rdict = {}
        
        if cmd[0] == 3:
            _, x = cmd
            x -= 1
            root = -1
            if x in rdict:
                root = rdict[x]
            else:
                children = []
                while parent[x] != -1:
                    children.append(x)
                    x = parent[x]
                
                root = x
                
                for chile in children:
                    rdict[chile] = root

            res = []
            while child[root] != -1:
                res.append(root+1)
                root = child[root]

            res.append(root+1)
            print(len(res), *res)


if __name__ == '__main__':
    main()