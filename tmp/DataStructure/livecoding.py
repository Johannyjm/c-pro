import numpy as np
from copy import deepcopy

a = np.ones([10, 10], dtype=np.int64)
# print(a)

b = deepcopy(a)
print(b)

print(a@b)

# print(a.dot(b))
# print(np.dot(a, b))


print(a*b)