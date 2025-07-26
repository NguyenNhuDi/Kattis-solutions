import math
import queue

def main():
    n = int(input())

    out = 0
    for i in range(n):
        if input() == 'O':
            out += 2 ** (n - (i + 1))

    
    print(out)

main()
