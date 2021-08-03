def digit(n: int) -> int:
    
    ret = 0
    while n:
        n //= 10
        ret += 1

    return ret

print(digit(12345))
        
