import sys
import math
import queue
import heapq
import itertools

MOD = 1000000007
INT_MAX = 2147483647
INT_MIN = -2147483648

def solve(dp, jump, pos, costs):
    n = len(costs)

    if pos < 0 or pos >= n:
        return INT_MAX
    
    if pos == n - 1:
        return costs[pos]

    if dp[pos][jump] != INT_MAX:
        return dp[pos][jump]
    
    dp[pos][jump] = costs[pos] + min(solve(dp, jump, pos - jump, costs), solve(dp, jump + 1, pos + jump + 1, costs))
    return dp[pos][jump]


def main():
    n = int(input())

    costs = [int(input()) for _ in range(n)]

    dp = [[INT_MAX for j in range(n)] for i in range(n)] 

    dp[0][0] = 0

    print(solve(dp, 1, 1, costs))
main()