def ok(a, b):
    if a[0] == 1 or t[i] == 2:
        if b[0] == 1 or b[0] == 3:
            if(b[2] < a[1]) return False;
        
        if b[0] == 2 or b[0] == 4:
            if r[j] <= l[i]: return False;
        
    if a[0] == 3 or a[0] == 4:
        if r[j] <= l[i]: return False;
    
    if a[0] == 1 or a[0] == 3:
        if b[0] == 1 or b[0] == 2:
            if r[i] < l[j]: return False;
    
        if b[0] == 3 or b[0] == 4:
            if r[i] <= l[j]: return False;
        
    
    if a[0] == 2 or a[0] == 4:
        if r[i] <= l[j]: return False;
 
    return True

def main():
    n = int(input())
    intervals = [list(map(int, input().split())) for _ in range(n)]

    res = 0
    for i in range(n):
        for j in range(i+1, n):

            if ok(interval[i], interval[j]):
                res += 1
    
    print(res)



if __name__ == '__main__':
    main()