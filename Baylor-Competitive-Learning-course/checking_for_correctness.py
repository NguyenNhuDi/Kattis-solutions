from sys import stdin

def exp(x, n, M = 10000):
    res = 1

    while n >= 1:
        if n & 1:
            res = (res * x) % M;
            n -= 1
        else:
            x = (x * x) % M
            n //= 2
    return res


def main():
    for line in stdin:
        l, op, r = line.split('\n')[0].split()
        l, r = map(int, (l, r))

        if op == '+':
            print((l + r) % 10000)
        elif op == '*':
            print((l * r) % 10000)
        else:
            print(exp(l, r))

if __name__ == '__main__':
    main()