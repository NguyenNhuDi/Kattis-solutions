#bit by bit

from sys import stdin
import math
import queue

def main():
    while True:
        n = int(input())

        if n == 0:
            break

        register = ['?' for i in range(32)]


        for _ in range(n):
            inpoo = input().split()

            # set and clear situation
            if len(inpoo) == 2:
                if inpoo[0] == 'SET':
                    register[int(inpoo[1])] = 1
                else:
                    register[int(inpoo[1])] = 0
            else:
                i = int(inpoo[1])
                j = int(inpoo[2])

                if inpoo[0] == 'AND':
                    if register[j] == 0 or register[i] == 0:
                        register[i] = 0
                    
                    else:
                       if register[i] == '?' or register[j] == '?':
                            register[i] = '?'
                       else:
                            register[i] = 1
                else:
                    if register[j] == 1 or register[i] == 1:
                        register[i] = 1
                    else:
                        if register[i] == '?' or register[j] == '?':
                            register[i] ='?'
                        else:
                            register[i] = 0

        register.reverse()

        for c in register:
            print(c, end='')
        print()
                

main()
