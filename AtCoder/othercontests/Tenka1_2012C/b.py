s = input()
mark = {
    'S': 0, 
    'H': 1, 
    'D': 2, 
    'C': 3
}
num = {
    'A': 0, 
    '2': 1, 
    '3': 2, 
    '4': 3, 
    '5': 4, 
    '6': 5, 
    '7': 6, 
    '8': 7, 
    '9': 8, 
    '1': 9, 
    'J': 10, 
    'Q': 11, 
    'K': 12
}

marks = []
nums = []
ptr = 0
while(ptr < len(s)):
    if(s[ptr] == '0'): 
        ptr += 1
        if(ptr >= len(s)): break
    
    marks.append(mark[s[ptr]])
    ptr += 1
    nums.append(num[s[ptr]])
    ptr += 1

# print(marks)
# print(nums)

n = len(marks)
rsf = [[0 for _ in range(13)] for __ in range(4)]
res_m = -1
end = -1
b_flg = False
for i in range(n):
    if(nums[i] not in (0, 9, 10, 11, 12)): continue
    
    rsf[marks[i]][nums[i]] = 1
    for j in range(4):
        if(sum(rsf[j]) == 5):
            res_m = j
            end = i
            b_flg = True
            break
    
    if(b_flg): break

# print(end)
if(end == 4): 
    print(0)
    exit()

for i in range(end+1):
    if(marks[i] == res_m and nums[i] in (0, 9, 10, 11, 12)): continue
    print(list(mark.keys())[marks[i]], end='')
    print(list(num.keys())[nums[i]], end='')
    if(nums[i] == 9): print('0', end='')
print()