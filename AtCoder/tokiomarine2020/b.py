a, v = map(int, input().split())
b, w = map(int, input().split())
t = int(input())

start1 = a
end1 = a+v*t
start2 = b
end2 = b+w*t
if(a==b):
    print("YES")
    exit()
if(w>=v):
    print("NO")
    exit()

dist = abs(a-b)
rv = abs(v-w)

if(dist <= t*rv): print("YES")
else: print("NO")