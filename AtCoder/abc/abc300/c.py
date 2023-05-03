def check_valid(ni, nj, h, w, c):
    if ni >= h or ni < 0 or nj >= w or nj < 0:
        return False
        
    if c[ni][nj] != "#":
        return False

    return True

def count_and_remove_cross(h, w, c, s):

    found_center = []    
    for ci in range(s, h-s):
        for cj in range(s, w-s):

            if c[ci][cj] != "#": continue

            valid = True
            # validation
            ## ru
            for idx in range(1, s+1):
                ni = ci - idx
                nj = cj + idx

                if not check_valid(ni, nj, h, w, c):
                    valid = False
                    break
            ## rd
            for idx in range(1, s+1):
                ni = ci + idx
                nj = cj + idx

                if not check_valid(ni, nj, h, w, c):
                    valid = False
                    break
            ## ld
            for idx in range(1, s+1):
                ni = ci + idx
                nj = cj - idx

                if not check_valid(ni, nj, h, w, c):
                    valid = False
                    break
            ## lu
            for idx in range(1, s+1):
                ni = ci - idx
                nj = cj - idx

                if not check_valid(ni, nj, h, w, c):
                    valid = False
                    break

            if valid:
                found_center.append((ci, cj))
    
    # remove
    for ci, cj in found_center:

        c[ci][cj] = "."

        # ru
        for idx in range(1, s+1):
            c[ci-idx][cj+idx] = "."
        # rd
        for idx in range(1, s+1):
            c[ci+idx][cj+idx] = "."
        # ld
        for idx in range(1, s+1):
            c[ci+idx][cj-idx] = "."
        # lu
        for idx in range(1, s+1):
            c[ci-idx][cj-idx] = "."
    # print(s, found_center)
    return len(found_center)
        

def main():
    h, w = map(int, input().split())
    n = min(h, w)

    c = [list(input()) for _ in range(h)]

    res = [0] * n
    for s in range(n, 0, -1):

        res[s-1] = count_and_remove_cross(h, w, c, s)

        # for elem in c:
        #     print(*elem)
    

        
    print(*res)


if __name__ == '__main__':
    main()