ha, wa = map(int, input().split())
a = [input() for _ in range(ha)]

hb, wb = map(int, input().split())
b = [input() for _ in range(hb)]

hx, wx = map(int, input().split())
x = [input() for _ in range(hx)]

def valid_a(sai, saj):

    for i in range(ha):
        for j in range(wa):

            if a[i][j] == "#":

                if sai + i < 0 or sai + i >= hx or saj + j < 0 or saj + j >= wx:
                    return False
                if x[sai + i][saj + j] == ".":
                    return False
    return True

def valid_b(sbi, sbj):

    for i in range(hb):
        for j in range(wb):

            if b[i][j] == "#":

                if sbi + i < 0 or sbi + i >= hx or sbj + j < 0 or sbj + j >= wx:
                    return False
                if x[sbi + i][sbj + j] == ".":
                    return False
    return True

def check(sai, saj, sbi, sbj):
    
    seen = [[False] * wx for _ in range(hx)]

    for i in range(ha):
        for j in range(wa):

            if a[i][j] == "#":
                seen[sai + i][saj + j] = True
    
    for i in range(hb):
        for j in range(wb):

            if b[i][j] == "#":
                seen[sbi + i][sbj + j] = True
    
    for i in range(hx):
        for j in range(wx):

            if x[i][j] == "#":
                if not seen[i][j]:
                    return False
    
    return True



def main():

    for sai in range(-hx, hx):
        for saj in range(-wx, wx):

            if valid_a(sai, saj):

                for sbi in range(-hx, hx):
                    for sbj in range(-wx, wx):

                        if valid_b(sbi, sbj):

                            if check(sai, saj, sbi, sbj):

                                print("Yes")
                                exit()
    
    print("No")

if __name__ == '__main__':
    main()