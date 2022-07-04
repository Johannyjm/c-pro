from collections import deque

def main():
    k = int(input())
    if k < 10:
        print(k)
        exit()

    q = deque(range(1, 10))

    count = 9
    while len(q) > 0:

        v = q.popleft()

        for delta in (-1, 0, 1):
            nv = v%10 + delta

            if nv<0 or nv>=10: continue

            count += 1
            l_num = int(str(v) + str(nv))

            if count == k:
                print(l_num)
                exit()
            
            q.append(l_num)

if __name__ == '__main__':
    main()