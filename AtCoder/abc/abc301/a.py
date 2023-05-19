def main():
    n = int(input())
    s = input()
    takahashi_won = True

    t = 0
    a = 0
    for m in s:
        if m == 'T':
            t += 1
        else:
            a += 1

        if t > a:
            takahashi_won = True
        if a > t:
            takahashi_won = False
    
    if takahashi_won:
        print("T")
    else:
        print("A")

if __name__ == '__main__':
    main()