from sys import stdin
import math
import queue
import heapq

def main():
    n = int(input())

    *inpoo, = input()

    stack = []

    for i in range(len(inpoo)):
        curr = inpoo[i]
        
        #input case
        if curr == '{' or curr == '[' or curr == '(':
            stack.append(curr)
        else:
            try:
                top = stack.pop()

                if (curr == '}' and top != '{') or (curr == ']' and top != '[') or ((curr == ')' and top != '(')):
                    print(curr, i)
                    return
                elif curr == ' ':
                    stack.append(top)
            except IndexError:
                if curr != ' ':
                    print(curr, i)
                    return

    print('ok so far')
        
main()
