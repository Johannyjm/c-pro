def main():
    s = input()

    dsm = 0
    for c in s:
        dsm += int(c)
    
    if dsm%9 == 0:
        print("Yes")
    else:
        print("No")

if __name__ == '__main__':
    main()