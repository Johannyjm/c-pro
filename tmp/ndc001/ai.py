y = int(input())

isuru = False
if y % 4 == 0:
    isuru = True
if y % 100 == 0:
    isuru = False
if y % 400 == 0:
    isuru = True
