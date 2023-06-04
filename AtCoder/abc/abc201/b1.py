def main():
    n = int(input())
    st = [input().split() for _ in range(n)]
    print(st)
    st = [[int(t), s] for s, t in st]
    print(st)

    st.sort(reverse=True)

    print(st[1][1])    

if __name__ == '__main__':
    main()