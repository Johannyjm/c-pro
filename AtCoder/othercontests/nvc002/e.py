def main():
    s = input()
    k = len(s)

    count = s.count('o')

    if count + (15 - k) >= 8:
        print("YES")
    else:
        print("NO")

if __name__ == '__main__':
    main()