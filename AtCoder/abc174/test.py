def f(n):
    ret = 0
    while(n):
        n = n%bin(n).count('1')
        ret += 1
    return ret

seq = 55555555
for i in range(seq, seq+100):

    if(i > seq and i < seq+100): print(i, bin(i).count('1'), f(i))