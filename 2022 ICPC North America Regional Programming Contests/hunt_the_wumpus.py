from sys import stdin

def dist(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def main():
    seed = int(input())

    pos = set()

    while len(pos) < 4:
        seed = seed + (seed // 13) + 15

        npos = ((seed % 100) // 10, (seed % 100) % 10)
        pos.add(npos)

    it = 0
    while len(pos) > 0:
        coord = input()
        x, y = int(coord[0]), int(coord[1])

        if (x, y) in pos:
            print("You hit a wumpus!")
            pos.remove((x, y))
        it += 1
        if len(pos) == 0:
            break

        mini = 0xffffffffffffffffffffffffffffffffffffffffffffffffff

        for point in pos:
            mini = min(mini, dist(point, (x, y)))
        
        print(mini)
    print(f'Your score is {it} moves.')
        
if __name__ == '__main__':
    main()