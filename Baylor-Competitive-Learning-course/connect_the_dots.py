from sys import stdin
import string

def solve(board, dots):
    for i in range(0, len(dots) - 1):
        x, y = dots[i], dots[i + 1]
        if x[1] == y[1]: # same row case
            l = min(x[2], y[2])
            r = max(x[2], y[2])

            for j in range(l, r + 1):
                if board[x[1]][j] == '|':
                    board[x[1]][j] = '+'
                elif board[x[1]][j] == '.':
                    board[x[1]][j] = '-'

        else: # same col case
            l = min(x[1], y[1])
            r = max(x[1], y[1])

            for j in range(l, r + 1):
                if board[j][x[2]] == '-':
                    board[j][x[2]] = '+'
                elif board[j][x[2]] == '.':
                    board[j][x[2]] = '|'

    for i in board:
        for j in i:
            print(j, end='')
        print()

def main():
    sorter = {}

    index = 0
    for c in string.digits:
        sorter[c] = index
        index += 1
    
    for c in string.ascii_lowercase:
        sorter[c] = index
        index += 1

    for c in string.ascii_uppercase:
        sorter[c] = index
        index += 1

    row = 0
    dots = []
    board = []    
    for line in stdin:
        inpoo = line.split('\n')[0]
        if len(inpoo) == 0:
            dots.sort(key=lambda x : sorter[x[0]])

            solve(board, dots)

            board = []
            dots = []
            row = 0
            print()
            continue

        for col in range(len(inpoo)):
            if inpoo[col] != '.':
                dots.append((inpoo[col], row, col))
        
        board.append(list(inpoo))
        row += 1

    dots.sort(key=lambda x : sorter[x[0]])
    solve(board, dots)

if __name__ == '__main__':
    main()