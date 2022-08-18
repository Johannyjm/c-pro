import numpy as np
def main():
    _ = input()
    a = np.array(list(map(int, input().split())))
    b = np.array(list(map(int, input().split())))
    
    if a@b == 0:
        print("Yes")
    else:
        print("No")


if __name__ == '__main__':
    main()
# def main():
#     n = int(input())

#     a = list(map(int, input().split()))
#     b = list(map(int, input().split()))

#     orth = 0
#     for i in range(n):
#         orth += a[i] * b[i]

#     if orth == 0:
#         print("Yes")
#     else:
#         print("No")

# if __name__ == '__main__':
#     main()