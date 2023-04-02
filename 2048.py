def input_to_list(first, second, third, fourth):
    board = [[], [], [], []]

    first = first.split(" ")

    for value in first:
        board[0].append(int(value))

    second = second.split(" ")

    for value in second:
        board[1].append(int(value))

    third = third.split(" ")

    for value in third:
        board[2].append(int(value))

    fourth = fourth.split(" ")

    for value in fourth:
        board[3].append(int(value))

    return board


def combine(board):

    for i in range(4):
        for j in range(3):

            if board[i][j] == board[i][j+1] and board[i][j] != 0:
                board[i][j] = board[i][j] * 2
                board[i][j+1] = 0

    return board


def transpose(board):
    new_board = []

    for i in range(4):
        new_board.append([])
        for j in range(4):
            new_board[i].append(board[j][i])

    return new_board


def reverse(board):
    new_board = []

    for i in range(4):
        new_board.append([])
        for j in range(4):
            new_board[i].append(board[i][3-j])

    return new_board


def move(board):
    new_board = []

    for i in range(4):
        new_board.append([0]*4)

    for j in range(4):
        pos = 0

        for k in range(4):
            if board[j][k] != 0:
                new_board[j][pos] = board[j][k]
                pos += 1

    return new_board


def move_left(board):
    new_board = board

    new_board = move(new_board)

    new_board = combine(new_board)

    new_board = move(new_board)

    return new_board


def move_right(board):
    new_board = board

    new_board = reverse(new_board)

    new_board = move_left(new_board)

    new_board = reverse(new_board)

    return new_board


def move_up(board):
    new_board = board

    new_board = transpose(new_board)

    new_board = move_left(new_board)

    new_board = transpose(new_board)

    return new_board


def move_down(board):
    new_board = board

    new_board = transpose(new_board)

    new_board = move_right(new_board)

    new_board = transpose(new_board)

    return new_board


first_line = input()
second_line = input()
third_line = input()
fourth_line = input()
move_command = int(input())

game = input_to_list(first_line, second_line, third_line, fourth_line)

if move_command == 0:
    for a in move_left(game):
        print(a[0], a[1],  a[2],  a[3])

elif move_command == 1:
    for b in move_up(game):
        print(b[0], b[1], b[2], b[3])

elif move_command == 2:
    for a in move_right(game):
        print(a[0], a[1], a[2], a[3])

elif move_command == 3:
    for a in move_down(game):
        print(a[0], a[1], a[2], a[3])
