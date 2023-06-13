def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    idx_count = [0] * (n+1)
    for elem in c:
        idx_count[elem] += 1

    elem_score = [0] * (n+1)
    for i in range(n):
        elem_score[b[i]] += idx_count[i+1]

    res = 0
    for elem in a:
        res += elem_score[elem]
    
    print(res)
    


if __name__ == '__main__':
    main()