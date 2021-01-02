def isCamel(s: str) -> str:
    ret = ""
    n = len(s)
    isprefix = True
    issuffix = False
    pre_ = 0
    post_ = 0
    buf = ""

    for i in range(n):
        if(isprefix and s[i] == '_'): pre_ += 1
        elif(isprefix and s[i].isalpha()):
            isprefix = False
            if(s[i].isupper()): return ""
            buf += s[i]
        
        elif(isprefix and s[i].isdigit()): return ""
        elif(not isprefix and not s[i].isupper()):
            if(not issuffix and s[i] == '_'):
                issuffix = True
                if(ret != ""): ret += '_'
                ret += buf
                buf = ""
                post_ += 1

            elif(not issuffix and s[i] != '_'):
                buf += s[i]

            elif(issuffix and s[i] != '_'): return ""
            elif(issuffix and s[i] == '_'): post_ += 1

        elif(not isprefix and s[i].isupper()):
            if(ret != ""): ret += '_'
            ret += buf
            buf = s[i].lower()

    if(buf != ""):
        if(ret != ""): ret += '_'
        ret += buf
 
    prefix = ""
    for _ in range(pre_): prefix += '_'
    suffix = ""
    for _ in range(post_): suffix += '_'
 
    return prefix + ret + suffix

 
def is_snake(s: str) -> str:
    ret = ""
    n = len(s)
    isprefix = True
    pre_ = 0
    buf = ""
    cnt = 0

    while(n-1-cnt>=0 and s[n-1-cnt]=='_'): cnt += 1
    
    for i in range(n):
        if(s[i].isupper()): return ""
        if(isprefix and s[i]=='_'): pre_ += 1
        elif(isprefix and s[i]!='_'):
            if(s[i].isdigit()): return ""
            isprefix = False
            buf += s[i]
    
        elif(not isprefix and s[i]=='_'):
            if(i < n-cnt+1 and buf==""): return ""
            if(buf!="" and buf[0].isdigit()): return ""
            for j in range(len(buf)): 
                if(j==0 and ret!=""): ret += buf[j].upper()
                else: ret += buf[j]
            buf = ""

        elif(not isprefix and s[i]!='_'):
            buf += s[i]

    if(buf != ""):
        for i in range(len(buf)):
            if(i==0 and ret!=""): ret += buf[i].upper()
            else: ret += buf[i]

    prefix = ""
    for i in range(pre_): prefix += '_'
    if(ret != ""):
        for i in range(cnt):
            ret += '_'
    
    return prefix + ret            

def main():
    s = input()
    # print(isCamel(s), is_snake(s))
    if(isCamel(s) != ""): print(isCamel(s))
    elif(is_snake(s) != ""): print(is_snake(s))
    else: print(s)

if __name__ == "__main__":
    main()