from sys import stdin

def main():
    n, m = map(int, input().split())
    drinks = [input() for i in range(n)]

    peoples = {}

    for i in range(m):
        name = input()
        if name in peoples:
            peoples[name] += 1 
        else:
            peoples[name] = 0

        print(drinks[peoples[name]])

if __name__ == '__main__':
    main()