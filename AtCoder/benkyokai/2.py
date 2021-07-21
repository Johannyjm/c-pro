n = int(input())

def valid(num):
    cnt = 0
    for i in range(1, num+1):
        if(num%i == 0): cnt += 1

    return cnt == 8

res = 0
for i in range(1, n+1):
    if i % 2 == 0: continue

    if valid(i): res += 1

print(res)