def main():
    n = int(input())
    st = set()

    cand = []
    for i in range(1, n+1):
        s, t = input().split()
        t = int(t)

        if s in st: continue

        st.add(s)
        cand.append((-t, i))
    
    cand.sort()

    print(cand[0][1])

if __name__ == '__main__':
    main()