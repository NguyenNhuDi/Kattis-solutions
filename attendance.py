#attendance

from sys import stdin
import math
import queue
import heapq

def main():
    

    n = int(input())

    inpoo = [input() for i in range(n)]

    r = 1
    absent = False

    for l in range(n):

        if l == n-1:
            if inpoo[l] != 'Present!':
                print(inpoo[l])
                absent = True
            continue

        if inpoo[r] != 'Present!' and inpoo[l] != 'Present!':
            print(inpoo[l])
            absent = True

        r += 1 
    
    if not absent:
        print('No Absences')
main()
