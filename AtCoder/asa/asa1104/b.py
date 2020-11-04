x = input()

legal = ['o', 'k', 'u']
ptr = 0
while(ptr < len(x)):
    if(x[ptr] == 'c'):
        if(ptr+1 == len(x)):
            print("NO")
            exit()
        if(x[ptr+1] != 'h'):
            print("NO")
            exit()
        else:
            ptr += 2
    
    if(x[ptr] not in legal):
        print("NO")
        exit()
    
    else: ptr += 1

print("YES")