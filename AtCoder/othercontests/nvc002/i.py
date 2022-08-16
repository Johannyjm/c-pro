from itertools import permutations


def main():
    n = int(input())
    p = list(map(int, input().split()))
    q = list(map(int, input().split()))

    r = sorted(p)

    pidx = -1
    qidx = -1
    idx = 0
    for perm in permutations(r):

        if list(perm) == p:
            pidx = idx
        if list(perm) == q:
            qidx = idx

        idx += 1

    print(abs(pidx - qidx))

if __name__ == '__main__':
    main()