from sys import stdin

def f(x, poly):
    out = 0
    for i, coef in enumerate(poly):
        out += coef * (x ** i)
    return out

def dxdy(x, poly):
    out = 0
    for i, coef in enumerate(poly):
        if i == 0:
            continue

        out += coef * i * (x ** (i - 1))
    return out

def solve(poly):
    eps = 1e-5
    x0 = 100
    prev = 1000

    while abs(prev - x0) > eps:
        prev = x0
        x0 -= (f(x0, poly) / (dxdy(x0, poly) + 1e-9))

    return x0



def main():
    n = int(input())

    for _ in range(n):
        poly = [int(x) for x in input().split()][1:]
        print(round(solve(poly)))

if __name__ == '__main__':
    main()