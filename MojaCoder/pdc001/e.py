def valid(num):
    divisors = []
    for i in range(1, num+1):
        if i*i > num: break
        if num % i == 0:
            divisors.append(i)
            divisors.append(num // i)

    divisors = list(set(divisors))
    m = len(divisors)
    
    for i in range(m):
        for j in range(i+1, m):
            for k in range(j+1, m):
                if divisors[i] + divisors[j] + divisors[k] == num: return True
    
    return False


n = int(input())

for i in range(1, n+1):
    if valid(i):
        print(i)