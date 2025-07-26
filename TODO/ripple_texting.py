# tripple texting

from sys import stdin
import math
import queue

def main():
    inpoo = input()

    w_len = len(inpoo) // 3

    all =[inpoo[0:w_len], inpoo[w_len:w_len * 2], inpoo[w_len*2:w_len*3]]

    all.sort()

    print(all[1])

main()
