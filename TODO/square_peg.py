from sys import stdin

def main():
    s, r = map(int, input().split())

    if (s * s * 2) ** 0.5 <= r * 2:
        print('fits')
    else:
        print('nope')

if __name__ == '__main__':
    main()