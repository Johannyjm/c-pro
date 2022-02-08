n = int(input())
a = list(map(int, input().split()))
c_neg = 0
absmin = 1 << 60
abssum = 0
zero = False
for e in a:
    if e < 0: c_neg += 1
    absmin = min(absmin, abs(e))
    abssum += abs(e)
    if e == 0:
        zero = True

if zero or (c_neg % 2 == 0):
    print(abssum)
else:
    print(abssum - absmin)
