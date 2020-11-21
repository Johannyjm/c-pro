s, p = map(int, input().split())
d = s*s-4*p
fr = max(1, int(d**0.5)) - 10
to = fr + 20
for i in range(fr, to+1):
    if(i*i == d):
        print("Yes")
        exit()

print("No")