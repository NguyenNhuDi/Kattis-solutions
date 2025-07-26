from sys import stdin
import math
import queue
import heapq
import itertools

MOD = 1000000007

INT_MAX = 2147483647
INT_MIN = -2147483648

def main():
    grades = [int(i) for i in input().split()]
    cGrade = int(input())

    lGrades = {0 : "A", 1 : "B", 2 : "C", 3 : "D", 4 : "E"}

    for i in range(len(grades)):
        if cGrade >= grades[i]:
            print(lGrades[i])
            return

    print("F")


main()