from collections import defaultdict

def calc(num):

    pf = defaultdict(int)
    for i in range(2, num):
        if i*i > num: break

        while num % i == 0:
            pf[i] += 1
            num //= i
        
    if num != 1:
        pf[num] = 1


    ret = 1
    for k in pf:
        if pf[k] % 2 == 1:
            ret *= k

    return ret



def main():

    n = int(input())    

    res = 0
    for i in range(1, n+1):
        k = calc(i)

        nk = k
        res += 1
        for j in range(2, n+1):
            nk = k * j*j

            if nk <= n:
                res += 1
            else:
                break
    
    print(res)






if __name__ == '__main__':
    main()