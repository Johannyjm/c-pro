n = int(input())
res = 0
for i in range(1, n+1):
    if('1' in str(i)):
        print(i, str(i).count('1'))
    res += str(i).count("1")

print(res)
