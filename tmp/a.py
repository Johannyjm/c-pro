n = int(input())
a = list(map(int, input().split()))

bit = [0] * (1<<20)
def add(i, x):
    ptr = i+1
    while ptr <= n:
        bit[ptr] += x
        ptr += (ptr & -ptr)

def get(i):
    ptr = i+1
    ret = 0
    while ptr > 0:
        ret += bit[ptr]
        ptr -= (ptr & -ptr)
    return ret


for i in range(n):
    add(i, a[i])


for i in range(n):
    print(get(i))
