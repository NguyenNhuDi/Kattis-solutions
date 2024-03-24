import sys
import math
import queue
import heapq
import itertools

MOD = 1000000007
INT_MAX = 2147483647
INT_MIN = -2147483648

def sum(x):
    return x*(x+1) // 2

dp = {}
def solve(lb, up, b):
    tup = (lb, up, b)
    if b == 1 or lb >= up-1:
        val = (lb + up) * (up-lb+1) / 2
        dp[tup] = val
        return val
    
    mini = INT_MAX * 10
    for x in range(up-1, lb, -1):
        ftup = (x+1, up, b)
        f = dp[ftup] if ftup in dp else solve(x+1, up, b)
        if f >= mini:
            break
        stup = (lb, x-1, b-1)
        s = dp[stup] if stup in dp else solve(lb, x-1, b-1)
        if s >= mini:
            break
        mini = min(mini, x + max(f, s))
    dp[tup] = mini
    return mini



def main():
    n = int(input())

    for i in range(n):
        b, ub = (int(x) for x in input().split())

        print(int(solve(0, ub, b)))



main()