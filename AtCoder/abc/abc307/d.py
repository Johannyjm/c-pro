def main():
    n = int(input())
    s = input()

    stack = []
    left = 0
    for c in s:
        if c == '(':
            left += 1
            stack.append(c)
        
        elif c == ')' and left > 0:

            while stack[-1] != '(':
                stack.pop()
            stack.pop()
            left -= 1
        
        else:
            stack.append(c)
    
    print(*stack, sep="")

if __name__ == '__main__':
    main()