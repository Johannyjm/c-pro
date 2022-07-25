L1, R1, L2, R2 = map(int, input().split())
 
# 重ならない場合
if R1 <= L2 or R2 <= L1:
    ans = 0
 
# どちらかが包括している場合
elif L1 <= L2 and R2 <= R1:
    ans = R2 - L2 + 1
 
elif L2 <= L1 and R1 <= R2:
    ans = R1 - L1 + 1
 
# 重なる場合
elif L2 <= R1:
    ans = R1 - L2
 
elif L1 <= R2:
    ans = R2 - L1
 
print(ans)