from sys import stdin
import math
import queue
import heapq

letters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' ]

def main():
    _ = input()
    *truths, = input().split()

    truth_map = {}

    for i, truth in enumerate(truths):
        bool = True if truth == 'T' else False
        truth_map[letters[i]] = bool

    *inpoo, = input().split()
    stack = []

    for i in inpoo:
        if i == '*':
            
            a = stack.pop()
            b = stack.pop()

            stack.append(a and b)
        elif i == '+':

            a = stack.pop()
            b = stack.pop()

            stack.append(a or b)

        elif i == '-':
            a = stack.pop()
            stack.append(not a)

        else:
            stack.append(truth_map[i])
    
    print('T' if stack[0] else 'F')

main()
