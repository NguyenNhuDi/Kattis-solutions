import math

n = 2  #
numbers = [int(num) for num in input().split(" ", n-1)]

h = numbers[0]
a = numbers[1]

angle = math.radians(a)

dis = h/math.sin(angle)

print(math.ceil(dis))

