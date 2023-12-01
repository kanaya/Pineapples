import math

for i in range(0, 16):
    theta = i * (360 / 16) + 360 / 32 + 90
    cos_theta = math.cos(math.radians(theta))
    sin_theta = math.sin(math.radians(theta))
    x = 36 + 15 * cos_theta
    y = 36 + 15 * sin_theta
    x2 = 36 + 18 * cos_theta
    y2 = 36 + 18 * sin_theta
    print("{}: ({:.2f}, {:.2f}), ({:.2f}, {:.2f}), {}".format(i + 17, x, y, x2, y2, 360 - theta))

