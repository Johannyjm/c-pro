def main():
    s = input()

    for c in s:
        if s.count(c) == 1:
            print(c)
            exit()
    print(-1)

if __name__ == '__main__':
    main()