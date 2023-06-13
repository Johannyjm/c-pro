def main():
    s = input()[:: -1]

    s = s.replace('6', 's').replace('9', 'n')
    s = s.replace('s', '9').replace('n', '6')

    print(s)

if __name__ == '__main__':
    main()