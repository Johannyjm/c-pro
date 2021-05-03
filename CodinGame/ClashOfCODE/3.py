import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

k = int(input())
q = input().split()
q.sort()
now = 1
for e in q:
    if int(e) < now:
        print(now-1)
        exit()
    now += 1
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)
print(now-1)
