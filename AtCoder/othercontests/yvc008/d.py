def main():
    w = input()

    for c in w:
        if c in 'aeiou':
            continue
        print(c, end='')
    print()

if __name__ == '__main__':
    main()