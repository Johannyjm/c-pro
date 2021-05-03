n = int(input())
userset = set()
for i in range(n):
    user = input()
    if user not in userset:
        print(i+1)
        userset.add(user)