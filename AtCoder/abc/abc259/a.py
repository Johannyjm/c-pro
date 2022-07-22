def main():
    n, m, x, t, d = map(int, input().split())
    
    if m >= x:
        print(t)
    else:
        print(t - d*(x-m))

if __name__ == '__main__':
    main()