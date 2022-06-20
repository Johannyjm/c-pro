def main():
    s = input()
    n = len(s)
    k = int(input())

    subs = []
    for length in range(1, k):

        for start in range(n-length+1):
            end = start + length

            # print(start, end)

            subs.append(s[start: end])

    subs = list(set(subs))

    subs.sort()
    # print(*subs, sep='\n')
    print(subs[k-1])

if __name__ == '__main__':
    main()