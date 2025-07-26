# Fun House

from sys import stdin
import math


def move_right(start):
    x, y = start
    x += 1

    start[0] = x

def move_left(start):
    x, y = start
    x -= 1

    start[0] = x

def move_up(start):
    x, y = start
    y -= 1

    start[1] = y

def move_down(start):
    x, y = start
    y += 1

    start[1] = y

counter = 1
while True:
    wl = (int(x) for x in input().split())

    w, l = wl

    if w == l and l == 0:
        break

    room = [list(input()) for i in range(l)]
    
    start_found = False
    start = None

    for y in range(w):
        for x in range(l):
            if room[y][x] == '*':
                start = [x, y]
                start_found = True
                break
        if start_found:
            break
    
    right = 'right'
    left = 'left'
    up = 'up'
    down = 'down'
    
    ix, iy = start
    curr_direction = left

    if iy == 0:
        curr_direction = down
    elif iy == l-1:
        curr_direction = up
    elif ix == 0:
        curr_direction = right


    c = '*'

    print(f'HOUSE {counter}')

    while c != 'x':

        if curr_direction == right:
            move_right(start)
        elif curr_direction == left:
            move_left(start)
        elif curr_direction == up:
            move_up(start)
        else:
            move_down(start)

        x, y = start
        c = room[y][x]


        if c == '\\':
            if curr_direction == right:
                curr_direction = down
            elif curr_direction == down:
                curr_direction = right
            elif curr_direction == left:
                curr_direction = up
            else:
                curr_direction = left
        elif c == '/':

            if curr_direction == right:
                curr_direction = up
            elif curr_direction == down:
                curr_direction = left
            elif curr_direction == left:
                curr_direction = down
            else:
                curr_direction = right

    room[start[1]][start[0]] = '&'

    for i in room:
        for char in i:
            print(char,end='')
        print()
    counter += 1
