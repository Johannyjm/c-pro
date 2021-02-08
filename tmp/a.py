n = int(input())
a = list(map(int, input().split()))

# e.g. a = [3, 1, 4, 1, 5, 9, 2]
# bubble sort

def valid(idx):
    if(a[idx] <= a[idx+1]): return True
    else: return False

def swap(idx):
    a[idx], a[idx+1] = a[idx+1], a[idx]

while(True):
    flg = True
    for j in range(n-1):
        if(not valid(j)):
            swap(j)
            flg = False
    if flg:
        break

print(a)



# e.g. a = [3, 1, 4, 1, 5, 9, 2]
# one 3, two 1, one 4, one 5, one 2
# cnt [0, 2, 1, 1, 1, 1, 0, 0, 0, 0, 1]
# a <= 100000

cnt = [0] * 110000

for e in a:
    cnt[e] += 1

for i in range(110000):
    if(cnt[i] == 0): continue
    for _ in range(cnt[i]):
        print(i, end=' ')
    #print(str(i) * cnt[i])

print()


def merge_sort(li):
    m = len(li)
    if(m == 1):
        return li

    l = li[: m//2]
    r = li[m//2: ]

    L = merge_sort(l)
    R = merge_sort(r)

    print(l, r, L, R)
    
    return merge(L, R)


# L: 1, 3, 4
# R: 2, 5, 9
# ret: 1, 2, 3, 4, 5, 9

def merge(L, R):
    L = L[::-1]
    R = R[::-1]
    ret = []
    while(True):
        if(len(L) == 0):
            ret += R
            break
        if(len(R) == 0):
            ret += L
            break

        el = L[-1]
        er = R[-1]
        if(el == er):
            ret.append(el)
            ret.append(er)
            L.pop()
            R.pop()
        elif(el < er):
            ret.append(el)
            L.pop()
        else:
            ret.append(er)
            R.pop()
    
    return ret

print(merge_sort(a))
