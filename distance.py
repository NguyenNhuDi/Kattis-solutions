import sys
import math
import queue
import heapq
import itertools

MOD = 1000000007
INT_MAX = 2147483647
INT_MIN = -2147483648

def solve(arr):
    out = 0
    sum_so_far = 0
    for i, elem in enumerate(arr):
        if i == 0:
            continue
        sum_so_far += i * (elem - arr[i-1])
        out += sum_so_far
    
    return out


def main():
    n = int(input())

    x = []
    y = []

    for _ in range(n):
        tx, ty = (int(x) for x in input().split())

        x.append(tx)
        y.append(ty)

    x.sort()
    y.sort()

    print(solve(x) + solve(y))



main()