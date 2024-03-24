import math
from sys import stdin

def main():

    while True:
        n, m = (int(x) for x in input().split())

        if n == 0 and m == 0:
            break


        best = []
        bA = -1
        bB = -1
        
        mini = 999999
        for i in range(n):
            a, b = (int(x) for x in input().split())

            if a > m:
                continue

            if b / a < mini:
                mini = b / a
                best = [(a, b)]

            elif b / a == mini:
                best.append((a, b))

        best.sort(reverse=True)
        
        if len(best) == 0:
            print("No suitable tickets offered")

        else:
            a, b = best[0]

            print(f'Buy {a} tickets for ${b}')

    
main()