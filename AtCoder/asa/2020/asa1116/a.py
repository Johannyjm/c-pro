s = input()
for i in range(26):
    c = chr(ord('a') + i)
    if(c not in s):
        print(c)
        exit()

print("None")