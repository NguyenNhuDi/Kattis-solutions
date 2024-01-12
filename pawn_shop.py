import math
import queue

def main():
    n = int(input())

    origin = [int(x) for x in input().split()]
    new = [int(x) for x in input().split()]

    r = 0

    oSet = {}
    nSet = {}
    while r < n:
        
        print(new[r], end=' ')

        oV = origin[r]
        nV = new[r]

        if oV in oSet:
            oSet[oV] += 1
        else:
            oSet[oV] = 1

        if nV in nSet:
            nSet[nV] += 1
        else:
            nSet[nV] = 1

        if oSet == nSet and r < n - 1:
            print('#', end=' ')

            oSet = {}
            nSet = {}

        r += 1      

    print()

main()
