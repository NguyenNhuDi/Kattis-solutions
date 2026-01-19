from sys import stdin
import string

def main():
    c_i = {}
    i_c = {}
    for i, c in enumerate(string.ascii_uppercase):
        c_i[c] = i
        i_c[i] = c

    secret = [int(i) for i in input()]
    n = int(input())

    for _ in range(n):
        out = ''

        inpoo = input()
        for i, c in enumerate(inpoo):
            out += i_c[c_i[inpoo[i]] * secret[i] % 26]
        print(out)


if __name__ == '__main__':
    main()