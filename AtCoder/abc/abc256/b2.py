def main():
    n = int(input())
    a = list(map(int, input().split()))

    bases = [False] * n
    res = 0
    for gain in a:
        bases[0] = True

        indices = []
        for i in range(len(bases)):
            if bases[i]:
                indices.append(i)
        
        for i in range(len(indices)):
            indices[i] += gain

        indices_post = []
        for idx in indices:
            if idx >= 4:
                res += 1
            else:
                indices_post.append(idx)
        
        bases = [False] * 4
        for idx in indices_post:
            bases[idx] = True

    print(res)


if __name__ == '__main__':
    main()