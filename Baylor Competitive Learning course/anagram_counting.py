# anagram counting

from sys import stdin
import math
import queue
from itertools import permutations as p

def fac(n):
    if n == 1:
        return 1
    
    return n * fac(n -1)


def main():

    for line in stdin:
        inpoo = list(line)[0:-1]

        dict = {}

        for c in inpoo:
            if c not in dict:
                dict[c] = 1
            else:
                dict[c] += 1

        # do the perms

        out = fac(len(inpoo))

        for c in dict:

            out //= fac(dict[c])

        print(out)

main()
    
    

