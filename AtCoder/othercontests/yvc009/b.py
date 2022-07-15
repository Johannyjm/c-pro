def main():
    n = input()

    if len(set(n[: 3])) == 1 or len(set(n[1: ])) == 1:
        print("Yes")
    else:
        print("No")

if __name__ == '__main__':
    main()