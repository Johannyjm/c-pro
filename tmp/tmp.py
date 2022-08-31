
from itertools import permutations


def main():
    s = list('segment')
    s.sort()

    used = set()
    res = 0
    for p in permutations(s):
        if ''.join(list(p)) in used: continue
        used.add(''.join(list(p)))

        ss = ''.join(list(p))
        si = -1
        se = -1
        se2 = -1
        sg = -1
        
        eflg = False
        for i in range(len(ss)):
            if ss[i] == 's':
                si = i
            if ss[i] == 'e':
                if eflg:
                    se2 = i
                else:
                    se = i
                    eflg = True
            if ss[i] == 'g':
                sg = i

        if si < se < sg or si < se2 < sg:
            res += 1

    print(res)

if __name__ == '__main__':
    main()