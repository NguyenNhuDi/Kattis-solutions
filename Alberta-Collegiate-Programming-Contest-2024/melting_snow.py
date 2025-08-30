from sys import stdin

def main():
    a, p = map(int, input().split())

    p /= 100

    out = a
    while abs(a - (out * p)) >= 1e-6:
        out -= out * p
        out += a

    print(f'{out:.6f}')     


if __name__ == '__main__':
    main()