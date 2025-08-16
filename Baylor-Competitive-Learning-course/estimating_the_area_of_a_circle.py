from sys import stdin
from math import pi

def main():
    for line in stdin:
        r, m, c = map(float, line.split('\n')[0].split())
        
        if r == 0 == m == c:
            break

        r2 = r * r
        d2 = (2*r) ** 2
        print(f'{pi * r2} {c / m * d2}')

if __name__ == '__main__':
    main()