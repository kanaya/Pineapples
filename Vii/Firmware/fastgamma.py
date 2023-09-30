n = 0
for i in range(256):
    x = i / 256
    y = x ** 2.0
    j = int(y * 256)
    print("{},".format(j), end=" ")
    n += 1
    if (n % 16 == 0):
        print("")
