# dont_be_fake

from sys import stdin
import math
import queue
import heapq

def main():
    n = int(input())

    inpoo = [[int(x) for x in input().split()[1:]] for i in range(n)]
    
    ans = {}

    for i in range(0, 86400):
        counter = 0
        for row in inpoo:
            for j in range(0, len(row), 2):
                if row[j] <= i <= row[j+1]:
                    counter += 1

        if counter in ans:
            ans[counter] += 1
        else:
            ans[counter] = 1
    
    out = max(ans)
    print(out)
    print(ans[out])    



main()
