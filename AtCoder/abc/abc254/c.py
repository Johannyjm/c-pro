from collections import defaultdict

def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    b = sorted(a)

    count1 = [defaultdict(int) for _ in range(k)]
    count2 = [defaultdict(int) for _ in range(k)]

    for i in range(n):
        count1[i%k][a[i]] += 1
        count2[i%k][b[i]] += 1
    
    if count1 == count2:
        print("Yes")
    else:
        print("No")
    # for i in range(k):
    #     if count1[i] != count2[i]:
    #         print("No")
    #         exit()
    
    # print("Yes")

if __name__ == '__main__':
    main()