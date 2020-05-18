n = int(input())
ab = [list(map(int, input().split())) for _ in range(n)]

ng = 0
ng_st = set()
ng_mp = dict()
for a, b in ab:
    ang = a/b
    if(ang in ng_st):
        ng += 1
        if(ng_mp.get(-1/ang) is None): ng_mp[-1/ang] = 1
        else: ng_mp[-1/ang] += 1
    else:
        ng_st.add(-1/ang)

print(ng, ng_st, ng_mp)
    