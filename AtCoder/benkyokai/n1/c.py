def main():
    n = input()
    dig = 0
    for c in n:
        dig += int(c)
    
    if(dig % 9 == 0): print("Yes")
    else: print("No")

if __name__ == '__main__':
    main()