def main():
    abc = list(map(int, input().split()))
    print(sum(abc) - min(abc))

if __name__ == '__main__':
    main()