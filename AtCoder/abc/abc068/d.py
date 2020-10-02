def proc(a):
    n = len(a)
    ret = 0
    while(max(a) >= n):
        mx = max(a)
        idx = a.index(mx)
        for i in range(n):
            if(i == idx): a[i] -= n
            else: a[i] += 1
        
        ret += 1
        # print(ret, a)
    
    return ret



def main():

    for i in range(1001):
        a = [i] * 30
        print(i, proc(a))

if __name__ == "__main__":
    main()