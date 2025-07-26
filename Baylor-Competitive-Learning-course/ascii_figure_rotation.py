# ascii figure rotation
from sys import stdin
import math
import queue

def main():

    first = True

    while True:
        n = int(input())

        if n == 0:
            break

        if first:
            first = False
        else:
            print()

        board = []

        maxi = -1
        for i in range(n):
            temp = input()
            temp = [x for x in temp if x != '\r']
            maxi = max(maxi, len(temp))
            board.append(list(temp))



        for i in range(n):
            diff = [' ' for i in range(maxi - len(board[i]))]
            board[i] += diff


        out_board = [['i' for __ in range(n)] for _ in range(maxi)]

        # for row in board:
        #     print(row)

        for y in range(n):
            for x in range(len(board[y])):
                nx = y
                ny = x
                char = board[y][x]
                if char == '-':
                    out_board[ny][nx] = '|'
                elif char == '|':
                    out_board[ny][nx] = '-'
                else:
                    out_board[ny][nx] = char


        for i in range(len(out_board)):

            out_board[i].reverse()

            while(out_board[i][-1] == ' '):
                out_board[i].pop()

        for row in out_board:
            print(''.join(row))
        
main()
