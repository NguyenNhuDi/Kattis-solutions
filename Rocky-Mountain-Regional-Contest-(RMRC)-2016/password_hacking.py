from sys import stdin

def main():
    n = int(input())
    passwords = [float(input().split()[1]) for i in range(n)]
    passwords = passwords[::-1]
    
    out = 0
    while len(passwords) > 0:
        print(passwords)
        out += passwords.pop()

        total = sum(passwords)
        for i in range(len(passwords)):
            passwords[i] /= total

    print(f'{out:.5f}')


if __name__ == '__main__':
    main()