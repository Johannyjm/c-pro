t, n = map(int, input().split())

# if (100*n) % t == 0:
#     print(100 // t + (n-1) * (100//t + 1))

print((100*n + n*t - 1) // t)