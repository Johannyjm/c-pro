n = int(input())

h = n // 3600
m = n % 3600 // 60
s = n % 60

print(str(h).zfill(2) + ":" + str(m).zfill(2) + ":" + str(s).zfill(2))



# res = ""
# if(h < 10): res += "0"
# res += str(h)
# res += ":"
# if(m < 10): res += "0"
# res += str(m)
# res += ":"
# if(s < 10): res += "0"
# res += str(s)

# print(res)
