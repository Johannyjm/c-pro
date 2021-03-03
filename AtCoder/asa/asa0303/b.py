answers = [0] * 11000

for x in range(1, 110):
    for y in range(1, 110):
        for z in range(1, 110):
            ans = x*x + y*y + z*z + x*y + y*z + z*x

            if ans > 10000: continue

            answers[ans] += 1

n = int(input())
for i in range(1, n+1):
    print(answers[i])

