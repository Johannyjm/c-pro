def main():
    for i in range(10):
        for j in range(10):
            print(i, j, (i+j)%10, (i*j)%10)

if __name__ == '__main__':
    main()