from math import factorial

def is_prime(x):
    if x == 1: return False
    
    for i in range(2, x+1):
        if i*i > x: break
        if x%i == 0: return False

    return True

for n in range(1, 100000):
    n_fact = factorial(n)

    for i in range(1, 100):
        if n_fact % (n + i) != 0:
            res_a = n+i
            # print(n, n + i, end=' ')
            break
    
    for i in range(1, 100):
        if is_prime(n + i):
            res_b = n+i
            # print(n + i)
            break
    
    if(res_a != res_b):
        print(n, res_a, res_b)