def main():

    t = int(input())

    for i in range(t):
        n, m = (int(x) for x in input().split())

        for j in range(m):
            _ = input()

        print(n-1)

main()