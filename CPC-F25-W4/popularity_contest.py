from sys import stdin

def main():
    n, m = map(int, input().split())

    friends = [0 for i in range(n + 1)]

    for i in range(m):
        l, r = map(int, input().split())

        friends[l] += 1
        friends[r] += 1

    for i in range(1, n + 1):
        print(friends[i] - i, end=' ')
    print()

if __name__ == '__main__':
    main()
    