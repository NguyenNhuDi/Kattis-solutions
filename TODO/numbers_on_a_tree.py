from sys import stdin
import math
import queue
import heapq

def main():
    inpoo = input().split()

    height = int(inpoo[0])
    nodes = 2 ** (height + 1) - 1

    if len(inpoo) == 1:
        print(nodes)
        return

    instruct = list(inpoo[1])
    prev = 1
    prev_dir = 'R'
    for i in range(len(instruct)):
        if instruct[i] == 'R':
            prev = 2 * prev if prev_dir == 'R' else 2 * prev + 1
        else:
            prev = 2 * prev if prev_dir == 'L' else 2 * prev - 1
        
        nodes -= prev
        prev_dir = instruct[i]
            
    print(nodes)
                   
main()
