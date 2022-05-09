import random

def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    hash_dict = {}
    for elem in (set(a) | set(b)):
        hash_dict[elem] = random.randint(10**16, 10**17)

    a_h = [0] * n
    b_h = [0] * n
    for i in range(n):
        a_h[i] = hash_dict[a[i]]
        b_h[i] = hash_dict[b[i]]

    a_set = [0] * n
    b_set = [0] * n

    a_used = set()
    b_used = set()
    a_set[0] = a_h[0]
    b_set[0] = b_h[0]
    a_used.add(a_h[0])
    b_used.add(b_h[0])

    for i in range(1, n):
        a_set[i] = a_set[i-1]
        if a_h[i] not in a_used:
            a_set[i] ^= a_h[i]
            a_used.add(a_h[i])

        b_set[i] = b_set[i-1]
        if b_h[i] not in b_used:
            b_set[i] ^= b_h[i]
            b_used.add(b_h[i])
    
    q = int(input())
    for _ in range(q):
        x, y = map(int, input().split())
        x -= 1
        y -= 1

        if a_set[x] == b_set[y]:
            print("Yes")
        else:
            print("No")


    # print(*a_set)
    # print(*b_set)


if __name__ == '__main__':
    main()