# guess_who

from sys import stdin
import math
import queue
import heapq

def main():
    n, m, q = (int(x) for x in input().split())

    inpoo = {}

    for i in range(n):
        inpoo[i] = list(input())

    for _ in range(q):
        pos, a = (x for x in input().split())
        pos = int(pos) - 1

        for i in range(n):
            try:
                if inpoo[i][pos] != a:
                    del inpoo[i]
            except KeyError:
                pass

    if len(inpoo) > 1:
        print('ambiguous')
        print(len(inpoo))
    else:
        print('unique')
        print(max(inpoo) + 1)


    
main()
