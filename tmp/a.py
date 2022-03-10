def main():
    s = input()

    for _ in range(100):
        res = ''
        for c in s:
            if c == 'A':
                res += 'BC'
            if c == 'B':
                res += 'CA'
            if c == 'C':
                res += 'AB'

        if len(res) > 100: res = res[: 100]
        s = res
        print(res)


if __name__ == '__main__':
    main()