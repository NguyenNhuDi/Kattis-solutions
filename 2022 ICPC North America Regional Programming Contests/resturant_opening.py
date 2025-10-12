from sys import stdin
def dist(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)


def main():
    n , m = map(int, input().split())

    inpoo = [[int(x) for x in input().split()] for i in range(n)]

    mini = 0xffffffffffffffffffffffffffffffffffffffffffffffffff

    for x1 in range(n):
        for y1 in range(m):

            cost = 0
            for x2 in range(n):
                for y2 in range(m):
                    cost += dist(x1, y1, x2, y2) * inpoo[x2][y2]

            mini = min(cost, mini)

    print(mini)


if __name__ == '__main__':
    main()