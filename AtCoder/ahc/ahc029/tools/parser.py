total = 0
for i in range(400):
    line = input()
    if i % 4 == 2:
        # print(f"test{i//4} {line}")
        total += int(line.split(":")[-1])
print("Total score:", total)