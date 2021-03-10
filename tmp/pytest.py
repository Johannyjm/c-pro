n = int(input())
# D1 = []
# D2 = []

# for i in range(n):
#     d1, d2 = map(int, input().split())
#     D1.append(d1)
#     D2.append(d2)

D = [list(map(int, input().split())) for i in range(n)]

flg = False
for i in range(n-2):

    if D[i][0] == D[i][1] and D[i+1][0] == D[i+1][1] and D[i+2][0] == D[i+2][1]:
        flg = True

if flg:
    print("Yes")
else:
    print("No")