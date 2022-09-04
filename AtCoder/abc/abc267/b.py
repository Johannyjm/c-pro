def main():
    n = 10
    s = '0' + input()

    if s[1] != '0':
        print("No")
        exit()

    pins = [0] * 7
    if s[7] == '1': pins[0] = 1
    if s[4] == '1': pins[1] = 1
    if s[8] == '1' or s[2] == '1': pins[2] = 1
    if s[5] == '1' or s[1] == '1': pins[3] = 1
    if s[9] == '1' or s[3] == '1': pins[4] = 1
    if s[6] == '1': pins[5] = 1
    if s[10] == '1': pins[6] = 1
    
    for i in range(7):
        for j in range(i+1, 7):
            for k in range(j+1, 7):

                if pins[i] == 1 and pins[j] == 0 and pins[k] == 1:
                    print("Yes")
                    exit()
    
    print("No")





if __name__ == '__main__':
    main()