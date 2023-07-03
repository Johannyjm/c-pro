from fractions import Fraction

def main():
    n = int(input())
    ratios = [(Fraction(0), -1)] * n
    
    for i in range(n):
        a, b = map(int, input().split())

        ratios[i] = -Fraction(a, a + b), i + 1

    ratios.sort()

    for i in range(n):
        print(ratios[i][1], end=" ")
    
    print()

    


if __name__ == "__main__":
    main()