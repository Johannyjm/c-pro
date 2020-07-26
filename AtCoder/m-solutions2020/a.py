x = int(input())

res = 0
if(400 <= x <= 599): res = 8
if(600 <= x <= 799): res = 7
if(800 <= x <= 999): res = 6
if(1000 <= x <= 1199): res = 5
if(1200 <= x <= 1399): res = 4
if(1400 <= x <= 1599): res = 3
if(1600 <= x <= 1799): res = 2
if(1800 <= x <= 1999): res = 1

print(res)