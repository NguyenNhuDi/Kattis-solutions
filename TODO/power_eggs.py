import math
import queue
import sys

def solve(l, r, egg, floor, dp):    
    if l > r:
        return -1
    
    if l > 32:
        return -1
    

    m = (l + r) // 2

    if dp[m][egg] == floor:
        return m
    
    elif floor < dp[m][egg]:
        if floor > dp[m-1][egg]:
            return m
        else:
            return solve(l, m-1, egg, floor, dp)
    else:
        return solve(m + 1, r, egg, floor, dp)

def main():

    dp = [[0 for i in range(33)] for j in range(33)]


    # dp[moves][eggs] -> how many floors can check with this many eggs
    for moves in range(1, 33):
        for eggs in range(1, 33):
            dp[moves][eggs] = 1 + dp[moves-1][eggs-1] + dp[moves-1][eggs]

    n = int(input())

    for i in range(n):
        f, e = (int(x) for x in input().split())

        ans = solve(1, 33, e, f, dp)
        
        print('Impossible' if ans < 0 else ans)
  
main()