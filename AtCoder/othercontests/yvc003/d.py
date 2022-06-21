def main():
    n = int(input())

    st = set()
    for _ in range(n):

        a = int(input())

        if a in st:
            st.discard(a)
        else:
            st.add(a)
    
    print(len(st))

if __name__ == '__main__':
    main()