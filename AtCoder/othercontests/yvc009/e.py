def main():
    n = int(input())
    p = list(map(int, input().split()))

    st = set()
    now = 0
    for i in range(n):
        st.add(p[i])

        while now in st:
            now += 1
        
        print(now)
    

if __name__ == '__main__':
    main()