def main():
    n = int(input())
    a = list(map(int, input().split()))
    
    abs_a = [0] * n
    neg_count = 0
    for i in range(n):
        abs_a[i] = abs(a[i])
        
        if a[i] < 0:
            neg_count += 1

    if 0 in a:
        print(sum(abs_a))
        exit()
    
    if neg_count % 2 == 0:
        print(sum(abs_a))
    
    else:
        print(sum(abs_a) - min(abs_a)*2)
        

if __name__ == '__main__':
    main()