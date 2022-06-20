def main():
    n = int(input())
    a = list(map(int, input().split()))

    a_i = [(a[i], i+1)for i in range(n)]

    a_i.sort(reverse=True)

    for i in range(n):
        print(a_i[i][1])

if __name__ == '__main__':
    main()