import sys
import math
import queue
import heapq
import itertools

MOD = 1000000007
INT_MAX = 2147483647
INT_MIN = -2147483648


def main():
    n = int(input())

    syl = set(input() for i in range(n))

    poem = [input().strip() for i in range(3)]

    ans = []
    for line in poem:
        
        # dp hold sets containing the number of different sylables possible
        dp = [set() for i in range(len(line))]
        dp.append(set([0]))

        for i in range(len(line) - 1, -1, -1): # loop the line from right to left
            if line[i] == ' ': 
                dp[i] = dp[i + 1] # its a blank, skip it (use the next available char)
            
            for l in range(1, 8):
                _i = i + l

                if _i <= len(line):
                    curr_syl = line[i:_i]
                    if curr_syl in syl:
                        dp[i] = dp[i] | set([x + 1 for x in dp[_i]]) # the sylable í an actual slyable, lets add it to all combos

        ans.append(dp[0]) # add all possible combo to ans


    print('haiku' if 5 in ans[0] and 7 in ans[1] and 5 in ans[2] else 'come back next year')




main()