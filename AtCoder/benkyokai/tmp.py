def digit_len(num: int) -> int:
    ret = 0
    while num:
        ret += 1
        num //= 10
    
    return ret

def main():
    n = int(input())

    res = 0
    for i in range(1, n+1):
        if digit_len(i) % 2 == 1:
            res += 1
    

    print(res)

if __name__ == '__main__':
    main()