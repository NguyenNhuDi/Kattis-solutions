from sys import stdin

def main():
    l, r = map(int, input().split())

    print(r // l + r % l)

if __name__ == '__main__':
    main()