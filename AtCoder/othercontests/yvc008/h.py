def main():
    s = input()
    n = len(s)

    res = 1001001001
    for i in range(1<<n):
        is_del = [False] * n
        count_del = 0

        for j in range(n):
            if i & (1<<j):
                is_del[j] = True
                count_del += 1
        
        d_sum = 0
        for j in range(n):
            if not is_del[j]:
                d_sum += int(s[j])
        
        if d_sum % 3 == 0:
            res = min(res, count_del)
    
    if res < n: print(res)
    else: print(-1)


if __name__ == '__main__':
    main()