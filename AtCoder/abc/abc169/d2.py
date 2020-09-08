def is_prime(n):
    if(n == 1): return False
    
    for i in range(2, n*0.5 + 2):
        if(n%i == 0): return False

    return True


n = int(input())

if(n==1):
    print(0)
    exit()

if(is_prime(n)):
    print(1)
    exit()

st = set()
for 