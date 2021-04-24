def divisor(n):
    ret = set()
    for i in range(1, n):
        if i*i > n: break

        if n%i == 0:
            ret.add(i)
            if i*i != n: ret.add(n//i)
    
    return ret



for i in range(100):
    st = divisor(i)

    even = 0
    odd = 0

    for m in st:
        if m%2 == 0: even += 1
        else: odd += 1
    
    if even == odd: print(i, 'same')
    elif even > odd: print(i, 'even')
    else: print(i, 'odd')