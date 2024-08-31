from sys import stdin
import math
import queue

def setFind(num, arr):
    if arr[num] < 0:
        return num
    num = arr[num]
    return setFind(num, arr)

def setUnion(a, b, arr):
    rootA = setFind(a, arr)
    rootB = setFind(b, arr)

    if rootA == rootB:
        return
    
    if arr[rootA] <= arr[rootB]:
        arr[rootA] += arr[rootB]
        arr[rootB] = rootA
    else:
        arr[rootB] += arr[rootA]
        arr[rootA] = rootB


def two_to_one(y, x, w):
    # arr[h][w] -> arr[i]
    return y * w + x


def main():
    h, w = (int(x) for x in input().split())
    
    sets = [-1 for i in range(h * w)]

    board = [list(input()) for i in range(h)]


    #creating the unions

    for y in range(h):
        for x in range(w):
            
            # checking neighbours
            for i in range(-1, 2, 2):
                nx = x + i
                ny = y + i

                type = board[y][x]

                index = two_to_one(y, x, w)
                h_index = two_to_one(y, nx, w)
                v_index = two_to_one(ny, x, w)

                if nx >= 0 and nx < w:
                    h_type = board[y][nx]
                    if h_type == type:
                        setUnion(h_index, index, sets)

                if ny >= 0 and ny < h:
                    v_type = board[ny][x]
                    if v_type == type:
                        setUnion(v_index, index, sets)


    n = int(input())


    for _ in range(n):    
        iy, ix, fy, fx = (int(x) - 1 for x in input().split())

        init_index = two_to_one(iy, ix, w)
        final_index = two_to_one(fy, fx, w)

        init_root = setFind(init_index, sets)
        final_root = setFind(final_index, sets)


        if init_root == final_root:
            type = board[iy][ix]

            if type == '0':
                print('binary')
            else:
                print('decimal')
        else:
            print('neither')

main()
