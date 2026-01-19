import sys
import math
MAXI = 1000001

sys.setrecursionlimit(10**9)

def sieve():
    primes = [True for i in range(MAXI)]
    out = []

    for i in range(2, MAXI):
        if primes[i]:
            out.append(i)

            for j in range(i * i, MAXI, i):
                primes[j] = False

    return out

def factor(x, tracker, primes):
    for p in primes:
        if p * p > x:
            break
        
        while x % p == 0:
            x //=p

            if p not in tracker:
                tracker[p] = 0

            tracker[p] += 1

    if x > 1:
        if x in tracker:
            tracker[x] += 1
        else:
            tracker[x] = 1

def main():
    primes = sieve()

    tracker = {}

    a, b = map(int, input().split())

    factor(a, tracker, primes)
    factor(b, tracker, primes)

    if len(tracker) == 2:
        for key in tracker:
            if tracker[key] >= 2:
                print('no credit')
                return 
        print('full credit')
    else:
        for key in tracker:
            if tracker[key] >= 2:
                print('no credit')
                return
        print(f'partial credit')

main()
