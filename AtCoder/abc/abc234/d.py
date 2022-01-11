n, k = map(int, input().split())
a = list(map(int, input().split()))

seen = [False] * (n+1)
for i in range(k):
    seen[a[i]] = True

ptr = 1
while not seen[ptr]:
    ptr += 1

print(ptr)

now = ptr

for i in range(k, n):
    
    if now < a[i]:
        
        seen[a[i]] = True
        ptr += 1
        while not seen[ptr]:
            ptr += 1

    print(ptr)

    now = ptr
