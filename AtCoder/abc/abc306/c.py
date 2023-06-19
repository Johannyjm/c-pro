from collections import defaultdict
def main():
    n = int(input())
    a = list(map(int, input().split()))

    count = defaultdict(int)
    for elem in a:
        count[elem] += 1
        if count[elem] == 2:
            print(elem, end=" ")
    print()

if __name__ == '__main__':
    main()