def main():
    s1 = input()
    s2 = input()
    s3 = input()

    s = (s1, s2, s3)
    for c in ('ABC', 'ARC', 'AGC', 'AHC'):
        if c not in s:
            print(c)
            exit()
        

if __name__ == '__main__':
    main()