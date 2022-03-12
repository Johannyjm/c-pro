def main():
    n, x = map(int, input().split())
    s = input()

    stack = []
    cs = ''
    for c in s:
        if c == 'U':
            if len(stack) == 0:
                cs += 'U'
            else:
                _, = stack.pop()
        
        else:
            stack.append(c)
    
    s = cs + ''.join(stack)

    
    now = x
    for c in s:
        if c == 'U': now //= 2
        if c == 'L': now = now*2
        if c == 'R': now = now*2 + 1

    print(now)

if __name__ == '__main__':
    main()