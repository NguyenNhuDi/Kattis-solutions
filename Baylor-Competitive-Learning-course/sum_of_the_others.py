#sum of the others

from sys import stdin


for line in stdin:

    numbers = [int(x) for x in line.split()]

    s = sum(numbers)

    for num in numbers:
        if num == s - num:
            print(num)
            break
