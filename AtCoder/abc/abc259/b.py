from math import sin, cos, pi
def main():
    a, b, d = map(int, input().split())
    dr = d * pi / 180
    print(cos(dr)*a - sin(dr)*b, sin(dr)*a + cos(dr)*b)

if __name__ == '__main__':
    main()