# even up solitaire

from sys import stdin
import math
import queue

def main():
    n = int(input())
    
    nums = [int(x) for x in input().split()]

    stack = []

    for i in range(n):
        if not len(stack):
            stack.append(nums[i])
            continue
        
        left = stack.pop()

        if (left + nums[i]) % 2 != 0:
            
            stack.append(left)
            stack.append(nums[i])


    print(len(stack))


main()
