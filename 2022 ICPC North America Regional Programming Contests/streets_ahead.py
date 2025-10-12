from sys import stdin

def main():
    n, q = map(int, input().split())

    inpoo = {}

    for i in range(n):
        inpoo[input()] = i

    for i in range(q):
        s, f = input().split()

        print(abs(inpoo[s] - inpoo[f]) - 1)

if __name__ == '__main__':
    main()