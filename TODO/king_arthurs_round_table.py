from sys import stdin

def main():
    d = float(input())
    w = float(input())
    h = float(input())

    if w * h < d * 3.14159:
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()