def main():
    l, r = map(int, input().split())

    res = 2022
    for i in range(l, min(l+2022, r)+1):
        for j in range(max(i+1, r-2022), r+1):

            res = min(res, i*j%2019)
    
    print(res)

            

if __name__ == '__main__':
    main()