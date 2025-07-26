from sys import stdin
import math
import queue
import heapq

def main():
    n = int(input())

    for _ in range(n):
        num = int(input())

        blanks = [-1 for i in range(num)]
        nums = [i for i in range(1,num+1)]
        index = 0

        first = True
        done = set()
        for i in nums:

            
            shift = 0
            while shift < i:
                if blanks[index] == -1:
                    shift += 1      
                index += 1
                index %= num

            if first:
                first = False
            else:
                while blanks[index] in done:
                    index += 1
                    index %= num

            blanks[index] = i 
            done.add(i)
            index += 1
            index %= num

        for num in blanks:
            print(num, end=' ')
        print()       


main()
