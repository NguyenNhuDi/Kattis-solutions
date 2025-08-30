from sys import stdin

def main():
    n = int(input())

    out = 0
    for i in range(n):
        t, a = map(int, input().split())

        out += a if not t else -a
        out = max(0, out)
    print(out)



if __name__ == '__main__':
    main()