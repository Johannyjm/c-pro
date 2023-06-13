def main():
    s = input()

    for c in reversed(s):
        if c == '6': print(9, end='')
        elif c == '9': print(6, end='')
        else: print(c, end='')
    print()

if __name__ == '__main__':
    main()