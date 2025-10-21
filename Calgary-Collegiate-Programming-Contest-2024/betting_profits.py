from sys import stdin

def main():
    n = int(input())

    for i in range(n):
        m, o, op = input().split()
        m, o = map(int, (m, o))

        if op == '+': # underdog
            o /= 100
        else:
            o = 100 / o

        print(f'{m * o:.5f}')


if __name__ == '__main__':
    main()