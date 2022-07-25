def main():
    n = int(input())
    count = dict()

    for _ in range(n):
        s = input()
        if s in count:
            print(s + '(' + str(count[s]) + ')')
            count[s] += 1
        else:
            count[s] = 1
            print(s)

if __name__ == '__main__':
    main()