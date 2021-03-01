k = int(input())

def divisor(n):
    ret = set()
    for i in range(1, int(n**0.5)+1):
        if n%i == 0:
            ret.add(i)
            ret.add(n//i)

    return len(ret) 

res = 0
for i in range(1, k+1):
    d = divisor(i)
    res += (k//i) * d

print(res)

