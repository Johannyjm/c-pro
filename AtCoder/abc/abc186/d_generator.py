import random
import numpy as np

n = random.randint(2, 20)

a = np.random.randint(-100000000, 100000000, [n,])
print(n)
for i in range(n):
    print(a[i], end=" ")
print()