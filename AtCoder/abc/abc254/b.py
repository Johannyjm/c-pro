def main():
    n = int(input())

    prev = [1]
    for i in range(n):
        print(*prev)

        now = [0] * (len(prev)+1)
        for j in range(len(prev)):
            now[j] += prev[j]
            now[j+1] += prev[j]
        
        prev = now

if __name__ == '__main__':
    main()