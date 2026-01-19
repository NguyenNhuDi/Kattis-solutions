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

        oSet[oV] = 1 if oV not in oSet else oSet[oV] + 1
        nSet[nV] = 1 if nV not in nSet else nSet[nV] + 1

        if oSet == nSet and r < n - 1:
            print('#', end=' ')

            oSet = {}
            nSet = {}

        r += 1      

    print()

main()
