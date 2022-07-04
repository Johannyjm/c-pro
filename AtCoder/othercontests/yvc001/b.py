def main():

    s = input()
    k = int(input())

    res_s = ''
    for c in s:
        if c == '1':
            res_s += c
        else:
            res_s += c
            break
    
    if len(res_s) > k-1:
        print(res_s[k-1])
    else:
        print(res_s[-1])

if __name__ == '__main__':
    main()