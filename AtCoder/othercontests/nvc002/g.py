def main():
    n = int(input())

    st = set()
    now = 1
    st.add(now)
    print(now)

    while True:
        k = int(input())
        if k == 0:
            break

        st.add(k)

        while now in st: now += 1

        print(now)
        
        st.add(now)

if __name__ == '__main__':
    main()