#How Many Digits?

from sys import stdin
import math

def fac(n):
    if n <= 1:
        return 1
    
    return n * fac(n-1)

for n in stdin:
    n = int(n)

    if n == 0 or n == 1:
        print(1)
        continue

    print(math.ceil(math.log10(math.sqrt(2 * n * math.pi)) + n * math.log10(n/math.e)))

